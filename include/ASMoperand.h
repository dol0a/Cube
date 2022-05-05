#pragma once

#include <string>

namespace Cube {
  struct Object;
  
  enum AsmOpKind {
    ASM_MOV,
    ASM_MOVI,

    ASM_ADD,
    ASM_MUL,

    ASM_ADDI,
  };

  struct AsmOperand {
    AsmOpKind kind;
    int regDest;
    int regSrc;
    
    Object* object;

    std::string toString() const;

    AsmOperand(AsmOpKind kind, int ra, int rb)
      : kind(kind),
        regDest(ra),
        regSrc(rb),
        object(nullptr)
    {
    }
  };
}