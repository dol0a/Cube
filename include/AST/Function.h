#pragma once

namespace Cube::AST {
  struct Function : Base {
    std::wstring_view name;
    Type* type;
  };
}