//
// Created by hudong on 6/30/15.
//

#ifndef FLEX_BISON_CPP_AST_NOT_NODE_H_
#define FLEX_BISON_CPP_AST_NOT_NODE_H_

#include "ast_logic_node.h"

namespace query_rewriter {
namespace query_parser {

class AstNotNode
    : public AstLogicNode {
 public:
  AstNotNode(AstNode *node);

  void Print() const override;
};

}  // namespace query_parser
}  // namespace query_rewriter

#endif  // FLEX_BISON_CPP_AST_NOT_NODE_H_
