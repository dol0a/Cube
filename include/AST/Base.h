#pragma once

namespace Cube::AST {
  struct Base {
    ASTKind kind;
    Token* token;

  protected:
    Base() { }
    virtual ~Base() { }
  };
}