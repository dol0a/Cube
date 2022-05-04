#pragma once

#include <string>

namespace Cube {
  struct Object;
  
  enum AsmOpKind {
    ASM_MOV,

    ASM_ADD,
  };

  struct AsmOperand {
    AsmOpKind kind;
    int regDest;
    int regSrc;
    
    Object* object;
  };
}