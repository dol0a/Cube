#pragma once

namespace Cube::AST {
  struct Variable : Base {
    std::wstring_view name;

    Variable() { kind = AST_VARIABLE; }
  };
}