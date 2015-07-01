#ifndef EXAMPLE_DRIVER_H
#define EXAMPLE_DRIVER_H

#include <string>
#include <vector>

#include "query_lexer.h"
#include "ast_node.h"

namespace query_rewriter {
namespace query_parser {

class Driver {
 public:
  Driver();

  ~Driver();

  bool parse_stream(std::istream &in,
                    const std::string &sname = "stream input");

  bool parse_string(const std::string &input,
                    const std::string &sname = "string stream");

  bool parse_file(const std::string &filename);

  void error(const class location &l, const std::string &m);

  void error(const std::string &m);

  AstNode *GetAstNode() const;

  void SetAstNode(AstNode *ast_node);

  std::string &GetStreamName();

  void SetStreamName(const std::string &name);

  void SetQueryLexer(QueryLexer *query_lexer);

  QueryLexer *GetQueryLexer() const;

 private:
  bool trace_scanning;

  bool trace_parsing;

  std::string streamname;

  QueryLexer *query_lexer_;

  AstNode *ast_node_;
};

}  // namespace query_parser
}  // namespace query_rewriter

#endif // EXAMPLE_DRIVER_H
