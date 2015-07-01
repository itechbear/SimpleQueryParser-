//
// Created by hudong on 6/30/15.
//

#include "ast_node.h"

#include <iostream>

namespace query_rewriter {
namespace query_parser {

AstNode::~AstNode() {
}

AstNode::AstNode(const Type &type)
    : type_(type) {
}

const AstNode::Type AstNode::GetType() const {
  return type_;
}

}  // namespace query_parser
}  // namespace query_rewriter
