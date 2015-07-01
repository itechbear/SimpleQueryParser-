//
// Created by hudong on 6/30/15.
//

#include "ast_not_node.h"

namespace query_rewriter {
namespace query_parser {

AstNotNode::AstNotNode(AstNode *node) : AstNode("NOT") {
  AddChild(node);
}

}  // namespace query_parser
}  // namespace query_rewriter
