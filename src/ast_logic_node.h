//
// Created by hudong on 7/1/15.
//

#ifndef SIMPLEQUERYPARSER_AST_LOGIC_NODE_H_
#define SIMPLEQUERYPARSER_AST_LOGIC_NODE_H_

#include "ast_node.h"

namespace query_rewriter {
namespace query_parser {

class AstLogicNode
    : public AstNode {
 public:
  AstLogicNode(const Type &type);

  virtual ~AstLogicNode();

  size_t GetChildrenCount() const;

  void AddChild(AstNode *node);

  virtual void Print() const override = 0;

 private:
  std::vector<AstNode *> children_;
};

}  // namespace query_parser
}  // namespace query_rewriter

#endif  // SIMPLEQUERYPARSER_AST_LOGIC_NODE_H_
