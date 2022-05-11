#pragma once

namespace Cube::AST {
  struct GetBuiltin : Base {
    Base* ast;

    GetBuiltin() { kind = AST_GETBUILTIN; }
  };
}