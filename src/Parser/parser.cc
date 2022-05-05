#include <cassert>
#include "Parser.h"

namespace Cube {
  Parser::Parser(Token* token)
    : cur(token),
      ate(nullptr)
  {
    assert(token != nullptr);
  }

  AST::Base* Parser::parse() {
    return add();
  }
}