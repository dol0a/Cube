#include "Parser.h"
#include "Error.h"
#include "Utils.h"

#include "dbg.h"

namespace Cube {
  AST::CallFunc* Parser::prsCallFunc() {
    expectIdent();

    auto x = new AST::CallFunc;
    x->token = cur;
    x->name = cur->str;

    next();

    expect(L"(");

    if( !eat(L")") ) {
      do {
        x->args.emplace_back(expr());
      } while( eat(L",") );
      expect(L")");
    }

    return x;
  }

  AST::Base* Parser::primary() {
    
    switch( cur->kind ) {
      case TOK_INT: {
        auto x = new AST::Value;

        auto obj = new ObjLong(std::stoi(std::wstring(cur->str)));

        x->token = cur;
        x->value = obj;

        next();
        return x;
      }

      case TOK_STRING: {
        auto x = new AST::Value;
        auto obj = new ObjString(cur->str);

        x->token = cur;
        x->value = obj;

        next();
        return x;
      }

      case TOK_IDENT: {
        if( cur->next->str == L"(" ) {
          return prsCallFunc();
        }

        auto x = new AST::Variable;

        x->token = cur;
        x->name = cur->str;

        next();
        return x;
      }
    }

    Error::append(cur, "invalid syntax");
    Error::crash();
  }

  AST::Base* Parser::unary() {
    if( eat(L"@") ) {
      auto x = new AST::GetBuiltin;
      x->token = ate;

      x->ast = primary();

      switch( x->ast->kind ) {
        case AST_VARIABLE:
        case AST_CALLFUNC:
          break;
        
        default:
          Error::append(x->token, "expected variable name or function call after `@`");
          Error::crash();
      }

      return x;
    }

    return primary();
  }

  AST::Base* Parser::mul() {
    auto x = unary();

    while( check() ) {
      if( eat(L"*") ) x = new AST::Expr(AST_MUL, x, unary(), ate);
      else if( eat(L"/") ) x = new AST::Expr(AST_DIV, x, unary(), ate);
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

  AST::Base* Parser::expr() {
    return add();
  }

}