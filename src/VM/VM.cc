#include "Object.h"
#include "VM.h"

namespace Cube {
  VM::VM(std::vector<u8> const& code)
    : code(code),
      ip(0),
      sp(0),
      lr(0),
      pc(0)
  {
  }

}