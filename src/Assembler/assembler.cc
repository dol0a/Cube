#include <cstdlib>
#include <cstring>
#include "ASMoperand.h"
#include "Assembler.h"
#include "Utils.h"

#include "dbg.h"

namespace Cube {

  Assembler::Assembler(std::vector<u8>& output, std::vector<AsmOperand> const& oplist)
    : output(output),
      oplist(oplist)
  {
  }
  
  template <class T, class... Args>
  void Assembler::push(T const& t, Args&&... args) {
    output.resize(output.size() + sizeof(T));
    *(T*)(&output[output.size() - sizeof(T)]) = t;

    if constexpr( sizeof...(args) ) {
      push(args...);
    }
  }

  void Assembler::asm_full() {

    for( auto&& op : oplist ) {
      if( op.kind == ASM_LABEL ) {
        labelMap[op.label] = &output[0] + output.size();
        continue;
      }

      push(op.kind);
 
      switch( op.kind ) {
        case ASM_MOV:
        case ASM_ADD:
        case ASM_MUL:
          push(op.regDest, op.regSrc);
          break;

        case ASM_MOVI:
        case ASM_ADDI:
          push(op.regDest, op.object);
          break;
        
        case ASM_CALL:
        case ASM_JUMP:
          push(labelMap[op.label]);
          break;

        case ASM_SYSCALL: {
          push(op.num);
          break;
        }

        case ASM_PUSH_ARG: {
          push(op.regDest);
          break;
        }

        case ASM_RETURN:
          break;

        default: {
          debug(
            alert;
            fprintf(stderr,"warn: AsmOpKind %d not handled\n", op.kind);
            exit(1);
          )

          break;
        }
      }
    }
    
  }


}