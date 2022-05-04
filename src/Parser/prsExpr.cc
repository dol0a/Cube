#include "Parser.h"
#include "Error.h"
#include "Utils.h"

namespace Cube {
  AST::Base* Parser::primary() {
    
    switch( cur->kind ) {
      case TOK_INT: {
        auto x = new AST::Value();

        auto obj = new ObjLong(std::stoi(std::wstring(cur->str)));

        x->token = cur;
        x->value = obj;

        next();
        return x;
      }
    }

    Error::append(cur, "invalid syntax");
    Error::crash();
  }

  AST::Base* Parser::mul() {
    auto x = primary();

    while( check() ) {
      if( eat(L"*") ) x = new AST::Expr(AST_MUL, x, primary(), ate);
      else if( eat(L"/") ) x = new AST::Expr(AST_DIV, x, primary(), ate);
      else break;
    }

    return x;
  }

  AST::Base* Parser::add() {
    auto x = mul();

    while( check() ) {
      if( eat(L"+") ) x = new AST::Expr(AST_ADD, x, mul(), ate);
      else if( eat(L"-") ) x = new AST::Expr(AST_SUB, x, mul(), ate);
      else break;
    }

    return x;
  }

}