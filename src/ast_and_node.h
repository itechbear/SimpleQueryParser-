//
// Created by hudong on 6/30/15.
//

#ifndef FLEX_BISON_CPP_AST_AND_NODE_H_
#define FLEX_BISON_CPP_AST_AND_NODE_H_

#include "ast_logic_node.h"

namespace query_rewriter {
namespace query_parser {

class AstAndNode
    : public AstLogicNode {
 public:
  AstAndNode(AstNode *left, AstNode *right);

  void Print() const;
};

}  // namespace query_parser
}  // namespace query_rewriter


#endif  // FLEX_BISON_CPP_AST_AND_NODE_H_
