#include "Assembler.h"
#include "Object.h"
#include "VM.h"

namespace Cube {
  void VM::calcObject(AsmOpKind kind, Object* lhs, Object* rhs) {
    switch( kind ) {
      case ASM_ADD: {
        switch( lhs->type.kind ) {
          case TYPE_LONG:
            ((ObjLong*)lhs)->value += ((ObjLong*)rhs)->value;
            break;
        }

        break;
      }

      case ASM_MUL: {
        switch( lhs->type.kind ) {
          case TYPE_LONG:
            ((ObjLong*)lhs)->value *= ((ObjLong*)rhs)->value;
            break;
        }

        break;
      }
    }
  }

}