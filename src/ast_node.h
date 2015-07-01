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
  AstNode(const std::string &name);

  virtual ~AstNode();

  size_t GetChildrenCount() const;

  void AddChild(AstNode *node);

  const std::string &GetName() const;

  void Print() const;

 private:
  const std::string name_;
  std::vector<AstNode *> children_;
};

}  // namespace query_parser
}  // namespace query_rewriter

#endif  // FLEX_BISON_CPP_AST_NODE_H_
