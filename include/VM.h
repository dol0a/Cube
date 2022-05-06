#pragma once

#include <vector>
#include <cstdint>
#include "ASMoperand.h"

namespace Cube {
  typedef uint8_t u8;

  class VM {
    std::vector<u8> const& code;

    Object* reg[28] { 0 };
    size_t ip, sp, lr, pc;

    void calcObject(AsmOpKind kind, Object* lhs, Object* rhs);

  public:
    explicit VM(std::vector<u8> const& code);

    void run();
  };

}