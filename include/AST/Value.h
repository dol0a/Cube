#pragma once

#include <cstdint>
#include <string>

namespace Cube::AST {
  struct Value : Base {
    Object* value;

    Value() {
      kind = AST_VALUE;
    }
  };
}