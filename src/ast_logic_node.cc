//
// Created by hudong on 7/1/15.
//

#include "ast_logic_node.h"

namespace query_rewriter {
namespace query_parser {

AstLogicNode::AstLogicNode(const AstNode::Type &type)
    : AstNode(type) {
}

size_t AstLogicNode::GetChildrenCount() const {
  return children_.size();
}

void AstLogicNode::AddChild(AstNode *node) {
  if (nullptr != node) {
    children_.push_back(node);
  }
}

AstLogicNode::~AstLogicNode() {
  for (auto node : children_) {
    delete node;
  }
}

}  // namespace query_parser
}  // namespace query_rewriter

