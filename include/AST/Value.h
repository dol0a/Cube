#pragma once

#include <cstdint>
#include <string>

namespace Cube::AST {
  struct Value : Base {
    union {
      int64_t val_int = 0;
      double val_float;
      wchar_t val_char;
      bool val_bool;
    };

    std::wstring_view val_str;

    Value() {
      kind = AST_VALUE;
    }
  };
}