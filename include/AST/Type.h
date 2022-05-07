#pragma once

namespace Cube::AST {
  struct Type : Base {
    std::wstring_view name;
    bool reference;
    size_t arr_depth;
    std::vector<Type*> elems;

    Type() {
      kind = AST_TYPE;
    }
  };
}