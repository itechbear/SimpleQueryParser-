%{
#include <string>

#include "query_lexer.h"

typedef query_rewriter::query_parser::Parser::token token;
typedef query_rewriter::query_parser::Parser::token_type token_type;

#define yyterminate() return token::END

#define YY_NO_UNISTD_H
%}

%option c++
%option batch
%option debug
%option yywrap nounput
%option stack
%option header-file="lexer.hh"

%{
  #define YY_USER_ACTION  yylloc->columns(yyleng);
%}

%%

%{
  yylloc->step();
%}


AND           { return token::AND; }
OR            { return token::OR; }
NOT           { return token::NOT; }
[^ \t\n\r()]+ { yylval->phrase = new std::string(yytext, yyleng); return token::PHRASE; }
[ \t\n\r]+    /* { yylloc->step(); } */
.             { return static_cast<token_type>(*yytext); }

%%

namespace query_rewriter {
namespace query_parser {

QueryLexer::QueryLexer(std::istream* in,
		                   std::ostream* out)
    : yyFlexLexer(in, out) {
}

QueryLexer::~QueryLexer() {
}

void QueryLexer::set_debug(bool is_debug_on) {
    yy_flex_debug = is_debug_on;
}

}  // namespace query_parser
}  // namespace query_rewriter

#ifdef yylex
  #undef yylex
#endif

int yyFlexLexer::yylex() {
    std::cerr << "in yyFlexLexer::yylex() !" << std::endl;
    return 0;
}

int yyFlexLexer::yywrap() {
    return 1;
}
