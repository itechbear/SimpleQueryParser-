//
// Created by hudong on 6/30/15.
//

#include "ast_or_node.h"

namespace query_rewriter {
namespace query_parser {

AstOrNode::AstOrNode(AstNode *left, AstNode *right)
    : AstLogicNode(OR) {
  AddChild(left);
  AddChild(right);
}

void AstOrNode::Print() const {

}

}  // namespace query_parser
}  // namespace query_rewriter
