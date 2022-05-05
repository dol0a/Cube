#pragma once

#include <vector>
#include "AST.h"
#include "ASMoperand.h"

namespace Cube {
  typedef uint8_t u8;

  class Compiler {
    std::vector<AsmOperand> oplist;

    void asmMov(u8 dest, u8 src);
    void asmMovI(u8 dest, Object* val);

    void asmAdd(u8 rA, u8 rB);
    void asmMul(u8 rA, u8 rB);

    void asmAddI(u8 rA, u8 rB, Object* val);

  public:
    Compiler() { }

    void compile(AST::Base* ast, int reg);

    void viewAll();

    std::vector<AsmOperand> const& get_oplist();

  };
}