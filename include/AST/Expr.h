#pragma once

namespace Cube::AST {
  struct Expr : Base {
    Base* lhs;
    Base* rhs;

    Expr(ASTKind kind, Base* lhs, Base* rhs, Token* token)
      : lhs(lhs), rhs(rhs)
    {
      this->kind = kind;
      this->token = token;
    }
  };
}