#include <iostream>
#include "Compiler.h"

#include "dbg.h"

namespace Cube {

  void Compiler::compile(AST::Base* ast, int reg) {
    
    if( !ast )
      return;
    
    switch( ast->kind ) {
      case AST_VALUE: {
        asmMovI(reg, ((AST::Value*)ast)->value);

        break;
      }

      case AST_FUNCTION: {
        auto x = (AST::Function*)ast;

        placeLabel(x->name);

        compile(x->code, 3);

        asmMov(0, 3);
        asmReturn();

        break;
      }

      case AST_SCOPE: {
        auto x = (AST::Scope*)ast;

        for( auto&& i : x->list ) {
          compile(i, reg);
        }

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

          case AST_MUL: {
            asmMul(reg, reg + 1);
            break;
          }
        }

        break;
      }
    }
  }

  void Compiler::viewAll() {
    for( auto&& Asm : oplist ) {
      std::cout << Asm.toString() << std::endl;
    }
  }

  std::vector<AsmOperand> const& Compiler::get_oplist() {
    return this->oplist;
  }
  

}