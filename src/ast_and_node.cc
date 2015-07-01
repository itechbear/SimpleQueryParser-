//
// Created by hudong on 6/30/15.
//

#include "ast_and_node.h"

namespace query_rewriter {
namespace query_parser {

AstAndNode::AstAndNode(AstNode *left, AstNode *right)
    : AstLogicNode(AND) {
  AddChild(left);
  AddChild(right);
}

void AstAndNode::Print() const {

}

}  // namespace query_parser
}  // namespace query_rewriter
