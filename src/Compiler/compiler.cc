#include "Compiler.h"

namespace Cube {

  void Compiler::compile(AST::Base* ast, int reg) {
    
    if( !ast )
      return;
    
    switch( ast->kind ) {
      case AST_VALUE: {
        asmMovI(reg, ((AST::Value*)ast)->value);

        break;
      }

      default: {
        auto x = (AST::Expr*)ast;

        compile(x->lhs, reg);
        compile(x->rhs, reg + 1);

        switch( x->kind ) {
          case AST_ADD: {
            asmAdd(reg, reg + 1);
            break;
          }
        }

        break;
      }
    }
  }

}