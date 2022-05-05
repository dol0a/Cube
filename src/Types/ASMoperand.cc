#include "Object.h"
#include "ASMoperand.h"
#include "Utils.h"

namespace Cube {
  using Utils::format;

  std::string AsmOperand::toString() const {
    switch( kind ) {
      case ASM_MOV:
        return format("mov r%d, r%d", regDest, regSrc);
      
      case ASM_MOVI:
        return format("movi r%d, %s", regDest, object->toString().c_str());

      case ASM_ADD:
        return format("add r%d, r%d", regDest, regSrc);

      case ASM_ADDI:
        return format("addi r%d, %s", regDest, object->toString().c_str());
    }

    return "";
  }
}