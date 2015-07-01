//
// Created by hudong on 6/30/15.
//

#include "ast_phrase_node.h"

namespace query_rewriter {
namespace query_parser {

AstPhraseNode::AstPhraseNode(const std::string &phrase)
    : AstNode(PHRASE), phrase_(phrase) {
}

const std::string &AstPhraseNode::GetPhrase() const {
  return phrase_;
}

void AstPhraseNode::Print() const {
}

}  // namespace query_parser
}  // namespace query_rewriter
