//
// Created by hudong on 6/30/15.
//

#ifndef FLEX_BISON_CPP_AST_AND_NODE_H_
#define FLEX_BISON_CPP_AST_AND_NODE_H_

#include "ast_node.h"

namespace query_rewriter {
namespace query_parser {

class AstAndNode
    : public AstNode {
 public:
  AstAndNode(AstNode *left, AstNode *right);
};

}  // namespace query_parser
}  // namespace query_rewriter


#endif  // FLEX_BISON_CPP_AST_AND_NODE_H_
