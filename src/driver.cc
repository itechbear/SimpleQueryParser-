// $Id$
/** \file driver.cc Implementation of the example::Driver class. */

#include <fstream>
#include <sstream>

#include "driver.h"
#include "query_lexer.h"

namespace query_rewriter {
namespace query_parser {

Driver::Driver()
    : trace_scanning(false), trace_parsing(false),
      ast_node_(nullptr), query_lexer_(nullptr) {
}

bool Driver::parse_stream(std::istream &in, const std::string &sname) {
  streamname = sname;

  QueryLexer *query_lexer = new QueryLexer(&in);
  query_lexer->set_debug(trace_scanning);
  this->query_lexer_ = query_lexer;

  Parser parser(*this);
  parser.set_debug_level(trace_parsing);
  return (parser.parse() == 0);
}

bool Driver::parse_file(const std::string &filename) {
  std::ifstream in(filename.c_str());
  if (!in.good()) return false;
  return parse_stream(in, filename);
}

bool Driver::parse_string(const std::string &input, const std::string &sname) {
  std::istringstream iss(input);
  return parse_stream(iss, sname);
}

void Driver::error(const class location &l,
                   const std::string &m) {
  std::cerr << l << ": " << m << std::endl;
}

void Driver::error(const std::string &m) {
  std::cerr << m << std::endl;
}

Driver::~Driver() {
  delete query_lexer_;
  delete ast_node_;
}

AstNode *Driver::GetAstNode() const {
  return ast_node_;
}

void Driver::SetAstNode(AstNode *ast_node) {
  ast_node_ = ast_node;
}

std::string &Driver::GetStreamName() {
  return streamname;
}

void Driver::SetStreamName(const std::string &name) {
  streamname = name;
}

void Driver::SetQueryLexer(QueryLexer *query_lexer) {
  query_lexer_ = query_lexer;
}

QueryLexer *Driver::GetQueryLexer() const {
  return query_lexer_;
}

}  // namespace query_parser
}  // namespace query_rewriter

