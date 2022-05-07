#pragma once

namespace Cube::AST {
  struct Scope : Base {
    std::vector<Base*> list;

    Scope() {
      kind = AST_SCOPE;
    }
  };
}