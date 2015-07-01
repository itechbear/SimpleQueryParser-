%{
#include <stdio.h>
#include <string>
#include <vector>

#include "ast_and_node.h"
#include "ast_or_node.h"
#include "ast_not_node.h"
#include "ast_phrase_node.h"
%}

%debug
%skeleton "lalr1.cc"
%start query
%defines
%define api.namespace { query_rewriter::query_parser }
%define parser_class_name { Parser }
%locations

%initial-action {
  @$.begin.filename = @$.end.filename = &driver.GetStreamName();
};

%parse-param { class Driver &driver }
%error-verbose

%union {
    std::string      *phrase;
    class AstNode    *ast_node;
}

%token END       0  "end of file"
%token AND
%token OR
%token NOT
%left  AND OR
%right NOT

%token <phrase>   PHRASE
%type <ast_node>  expression
%type <ast_node>  query
%type <ast_node>  and_logic
%type <ast_node>  or_logic

/*
%destructor { delete $$; } PHRASE
%destructor { delete $$; } expression
%destructor { delete $$; } query
*/

%{
#include "driver.h"
#include "query_lexer.h"

#undef yylex
#define yylex driver.GetQueryLexer()->lex
%}

%%

query  : expression                { $$ = $1; driver.SetAstNode($$); }
    | expression expression        { $$ = new AstAndNode($1, $2); driver.SetAstNode($$); }

expression : PHRASE                { $$ = new AstPhraseNode(*$1); }
    | NOT expression               { $$ = new AstNotNode($2); }
    | '(' expression ')'           { $$ = $2; }
    | PHRASE and_logic             { $$ = new AstAndNode(new AstPhraseNode(*$1), $2); }
    | NOT expression and_logic     { $$ = new AstAndNode(new AstNotNode($2), $3); }
    | '(' expression ')' and_logic { $$ = new AstAndNode($2, $4); }
    | PHRASE or_logic              { $$ = new AstOrNode(new AstPhraseNode(*$1), $2); }
    | NOT expression or_logic      { $$ = new AstOrNode(new AstNotNode($2), $3); }
    | '(' expression ')' or_logic  { $$ = new AstOrNode($2, $4); }

and_logic : AND expression         { $$ = $2; }

or_logic : OR expression           { $$ = $2; }

%%

void query_rewriter::query_parser::Parser::error(const Parser::location_type& l,
                            const std::string& m) {
    driver.PrintError(l, m);
}
