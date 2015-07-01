//
// Created by hudong on 6/30/15.
//

#ifndef FLEX_BISON_CPP_AST_PHRASE_NODE_H_
#define FLEX_BISON_CPP_AST_PHRASE_NODE_H_

#include "ast_node.h"

namespace query_rewriter {
namespace query_parser {

class AstPhraseNode
    : public AstNode {
 public:
  AstPhraseNode(const std::string &phrase);

  const std::string &GetPhrase() const;

  virtual void Print() const;

 private:
  const std::string phrase_;
};

}  // namespace query_parser
}  // namespace query_rewriter

#endif  // FLEX_BISON_CPP_AST_PHRASE_NODE_H_
