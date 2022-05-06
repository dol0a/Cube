#pragma once

#include <string>

namespace Cube {
  typedef uint8_t u8;
  
  enum AsmOpKind : u8 {
    ASM_MOV,
    ASM_MOVI,

    ASM_CMP,
    ASM_CMPI,

    ASM_ADD,
    ASM_SUB,
    ASM_MUL,
    ASM_DIV,

    ASM_ADDI,
    ASM_SUBI,
    ASM_MULI,
    ASM_DIVI,

    ASM_JUMP,
    ASM_CALL,
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