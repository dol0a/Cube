#pragma once

#include <string>
#include "AST.h"

namespace Cube {
  class Parser {
    Token* cur;
    Token* ate;

    bool check();
    void next();
    bool eat(std::wstring_view str);
    void expect(std::wstring_view str);

    void expectIdent();
    AST::Type* expectTypename();
    AST::Scope* expectScope();

  public:
    explicit Parser(Token* token);

    AST::Base* primary();
    AST::Base* mul();
    AST::Base* add();
    AST::Base* expr();

    AST::Base* top();

    AST::Base* parse();
  };
}