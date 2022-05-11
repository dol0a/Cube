#pragma once

#include <vector>
#include <cstdint>
#include "ASMoperand.h"

namespace Cube {
  typedef uint8_t u8;

  class VM {
  public:
    std::vector<u8> const& code;

    Object* reg[32] { 0 };
    std::vector<Object*> args;
    size_t ip, sp, lr, pc;

    void calcObject(AsmOpKind kind, Object* lhs, Object* rhs);

    void callBuiltinFunc(size_t num);

//  public:
    explicit VM(std::vector<u8> const& code);

    void run();
  };

}