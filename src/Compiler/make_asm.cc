#include "Compiler.h"

namespace Cube {
  void Compiler::asmMov(u8 dest, u8 src) {
    oplist.emplace_back(ASM_MOV, dest, src);
  }

  void Compiler::asmMovI(u8 dest, Object* val) {
    oplist.emplace_back(ASM_MOVI, dest, 0).object = val;
    
  }

  void Compiler::asmAdd(u8 dest, u8 src) {
    oplist.emplace_back(ASM_ADD, dest, src);
    
  }

  void Compiler::asmAddI(u8 rA, u8 rB, Object* val) {
    oplist.emplace_back(ASM_ADDI, rA, rB).object = val;
    
  }

}