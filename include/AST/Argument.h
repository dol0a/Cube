#pragma once

namespace Cube::AST {
  struct Argument : Base {
    std::wstring_view name;
    Type* type;

    Argument() {
      kind = AST_ARGUMENT;
    }
  };
}