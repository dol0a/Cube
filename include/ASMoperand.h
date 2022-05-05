#pragma once

#include <string>

namespace Cube {
  typedef uint8_t u8;
  
  enum AsmOpKind : u8 {
    ASM_MOV,
    ASM_MOVI,

    ASM_ADD,
    ASM_MUL,

    ASM_ADDI,
  };

  struct Object;
  struct AsmOperand {
    AsmOpKind kind;
    u8 regDest;
    u8 regSrc;
    
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