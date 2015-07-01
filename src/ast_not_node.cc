//
// Created by hudong on 6/30/15.
//

#include "ast_not_node.h"

namespace query_rewriter {
namespace query_parser {

AstNotNode::AstNotNode(AstNode *node) : AstLogicNode(NOT) {
  AddChild(node);
}

void AstNotNode::Print() const {
}

}  // namespace query_parser
}  // namespace query_rewriter
