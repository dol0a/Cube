#pragma once

namespace Cube::AST {
  struct GetBuiltin : Base {
    Base* ast;
    int num = 0;

    GetBuiltin() { kind = AST_GETBUILTIN; }
  };
}