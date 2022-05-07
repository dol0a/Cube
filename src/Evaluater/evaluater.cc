#include "Evaluater.h"
#include "Error.h"

#include "dbg.h"

namespace Cube {

  TypeInfo Evaluater::eval(AST::Base* ast) {
  __reject_null
  __ret_cache
    auto& ret = cache[ast];

    switch( ast->kind ) {
      case AST_VALUE: {
        switch( ast->token->kind ) {
          case TOK_INT: ret = TYPE_LONG; break;
        }

        alert;
        fprintf(stderr,"%p\n",((AST::Value*)ast)->value);

        break;
      }

      case AST_VARIABLE: {

        break;
      }

      case AST_FUNCTION: {
        auto x = (AST::Function*)ast;

      alert;
        ret = eval(x->code);

        break;
      }

      case AST_SCOPE: {
        for( auto&& i : ((AST::Scope*)ast)->list ) {
          eval(i);
        }

        break;
      }

      default: {
        ret = evalExpr(ast);
        break;
      }
    }

    return ret;
  }

  TypeInfo Evaluater::evalExpr(AST::Base* ast) {
  __reject_null
  __ret_cache
    auto x = (AST::Expr*)ast;
    auto& ret = cache[ast];

    auto lhs = eval(x->lhs);
    auto rhs = eval(x->rhs);

    if( !lhs.equals(rhs) ) {
      Error::append(x, "type mismatch");
    }

    return lhs;
  }
}