#pragma once

#include <cstdarg>

namespace Cube::Error {
  struct Token;
  namespace AST { struct Base; }

  void append(Token* token, char const* fmt, ...);
  void append(AST::Base* ast, char const* fmt, ...);
}