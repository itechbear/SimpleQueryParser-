//
// Created by hudong on 6/30/15.
//

#ifndef FLEX_BISON_CPP_AST_NODE_H_
#define FLEX_BISON_CPP_AST_NODE_H_

#include <cstddef>

#include <vector>
#include <string>

namespace query_rewriter {
namespace query_parser {

class AstNode {
 public:
  enum Type {
    AND,
    OR,
    NOT,
    PHRASE
  };

  AstNode(const Type &type);

  virtual ~AstNode();

  const Type GetType() const;

  virtual void Print() const = 0;

 private:
  const Type type_;
};

}  // namespace query_parser
}  // namespace query_rewriter

#endif  // FLEX_BISON_CPP_AST_NODE_H_
