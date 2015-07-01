#ifndef SRC_SCANNER_H_
#define SRC_SCANNER_H_

#ifndef YY_DECL

#define  YY_DECL            \
  query_rewriter::query_parser::Parser::token_type        \
  query_rewriter::query_parser::QueryLexer::lex(        \
  query_rewriter::query_parser::Parser::semantic_type* yylval,    \
  query_rewriter::query_parser::Parser::location_type* yylloc)
#endif

#ifndef __FLEX_LEXER_H

#include "FlexLexer.h"

#endif

#include "parser.tab.hh"

namespace query_rewriter {
namespace query_parser {

class QueryLexer
    : public yyFlexLexer {
 public:
  QueryLexer(std::istream *arg_yyin = 0,
             std::ostream *arg_yyout = 0);

  ~QueryLexer();

  Parser::token_type lex(Parser::semantic_type *yylval,
                         Parser::location_type *yylloc);

  void set_debug(bool b);
};

}  // namespace query_parser
}  // namespace query_rewriter

#endif  // SRC_SCANNER_H_
