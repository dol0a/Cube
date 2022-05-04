#pragma once

namespace Cube {
  enum ASTKind {
    AST_VALUE,
    AST_VARIABLE,
    AST_CALLFUNC,

    AST_ADD,
    AST_SUB,
    AST_MUL,
    AST_DIV,
    AST_MOD,

    AST_FUNCTION
  };
}