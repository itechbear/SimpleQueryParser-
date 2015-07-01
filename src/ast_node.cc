//
// Created by hudong on 6/30/15.
//

#include "ast_node.h"

#include <iostream>

namespace query_rewriter {
namespace query_parser {

size_t AstNode::GetChildrenCount() const {
  return children_.size();
}

AstNode::~AstNode() {
  for (auto node : children_) {
    delete node;
  }
}

void AstNode::AddChild(AstNode *node) {
  if (node != nullptr) {
    children_.push_back(node);
  }
}

AstNode::AstNode(const std::string &name)
    : name_(name) {
}

const std::string &AstNode::GetName() const {
  return name_;
}

void AstNode::Print() const {
  std::cout << GetName() << std::endl;

  for (auto node : children_) {
    node->Print();
  }
}

}  // namespace query_parser
}  // namespace query_rewriter
