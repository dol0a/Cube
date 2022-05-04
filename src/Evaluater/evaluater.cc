#include "Evaluater.h"
#include "Error.h"

namespace Cube {

  TypeInfo Evaluater::eval(AST::Base* ast) {
  __reject_null
  __ret_cache
    auto& ret = cache[ast];

    switch( ast->kind ) {
      case AST_VALUE: {
        switch( ast->token->kind ) {
          case TOK_INT: ret = TYPE_INT; break;
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