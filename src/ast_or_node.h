//
// Created by hudong on 6/30/15.
//

#ifndef FLEX_BISON_CPP_AST_OR_NODE_H_
#define FLEX_BISON_CPP_AST_OR_NODE_H_

#include "ast_logic_node.h"

namespace query_rewriter {
namespace query_parser {

class AstOrNode
    : public AstLogicNode {
 public:
  AstOrNode(AstNode *left, AstNode *right);

  void Print() const;
};

}  // namespace query_parser
}  // namespace query_rewriter

#endif  // FLEX_BISON_CPP_AST_OR_NODE_H_
