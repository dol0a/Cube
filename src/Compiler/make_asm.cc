#include "Compiler.h"

namespace Cube {
  void Compiler::asmMov(u8 dest, u8 src) {
    oplist.emplace_back(ASM_MOV, dest, src);
  }

  void Compiler::asmMovI(u8 dest, Object* val) {
    oplist.emplace_back(ASM_MOVI, dest, 0).object = val;
    
  }

  void Compiler::asmAdd(u8 rA, u8 rB) {
    oplist.emplace_back(ASM_ADD, rA, rB);
  }

  void Compiler::asmMul(u8 rA, u8 rB) {
    oplist.emplace_back(ASM_MUL, rA, rB);
  }

  void Compiler::asmAddI(u8 rA, u8 rB, Object* val) {
    oplist.emplace_back(ASM_ADDI, rA, rB).object = val;
    
  }

  void Compiler::asmReturn() {
    oplist.emplace_back(ASM_RETURN, 0, 0);
  }

  void Compiler::asmPushArg(int reg) {
    oplist.emplace_back(ASM_PUSH_ARG, reg, 0);
  }

  void Compiler::asmSyscall(int num) {
    oplist.emplace_back(ASM_SYSCALL, 0, 0).num = num;
  }

  void Compiler::placeLabel(std::wstring_view name) {
    oplist.emplace_back(ASM_LABEL, 0, 0).label = name;
  }
  

}