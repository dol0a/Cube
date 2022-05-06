#pragma once

#include <vector>
#include "ASMoperand.h"

namespace Cube {
  class Assembler {
    //u8* code;
    std::vector<u8>& output;
    std::vector<AsmOperand> const& oplist;

  public:
    explicit Assembler(std::vector<u8>& output, std::vector<AsmOperand> const& oplist);
    
    template <class T, class... Args>
    void push(T const& t, Args&&... args);

    void asm_full();
  };

  template <class T>
  auto derefCode(u8 const& p) {
    return *(T*)(&p);
  }
}