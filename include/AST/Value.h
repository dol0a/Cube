#pragma once

#include <cstdint>
#include <string>

namespace Cube::AST {
  struct Value : Base {
    Object* value = nullptr;

    Value() {
      kind = AST_VALUE;
    }
  };
}