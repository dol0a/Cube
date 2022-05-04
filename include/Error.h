#pragma once

#include <cstdarg>
#include "AST.h"

namespace Cube::Error {
  void append(Token* token, char const* fmt, ...);
  void append(AST::Base* ast, char const* fmt, ...);

  void check();
  void view_all();
  
  [[noreturn]]
  void crash();
}