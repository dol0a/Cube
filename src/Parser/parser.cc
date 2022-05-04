#include "Parser.h"

namespace Cube {
  Parser::Parser(Token* token)
    : cur(token),
      ate(nullptr)
  {
  }

  AST::Base* Parser::parse() {
    return add();
  }
}