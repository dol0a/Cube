#pragma once

namespace Cube {
  enum ASTKind {
    AST_VALUE,
    AST_VARIABLE,
    AST_CALLFUNC,

    AST_MEMBER_ACCESS,

    AST_ADD,
    AST_SUB,
    AST_MUL,
    AST_DIV,
    AST_MOD,

    AST_LET,

    AST_IF,
    AST_FOR, // for a; b; c
    AST_FOR_LIST, // for i : a // i = iterator<a>
    AST_FOR_RANGE, // for i in n .. m
    AST_LOOP,
    AST_WHILE,
    AST_DOWHILE,

    AST_SCOPE,

    AST_TYPE,
    AST_ARGUMENT,
    AST_FUNCTION
  };
}