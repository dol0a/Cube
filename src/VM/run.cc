#include "Assembler.h"
#include "Object.h"
#include "VM.h"

#include "dbg.h"

#define  loopEnd  goto LOOP_BEGIN

namespace Cube {
  
  void VM::run() {

    static void* jumpTable[] = {
      &&DO_MOV,
      &&DO_MOVI,
      &&DO_ADD,
      &&DO_MUL,
      &&DO_ADDI,
    };

    auto op = code.begin();

  LOOP_BEGIN:;
    if( op == code.end() ) {
      return;
    }

    auto kind = static_cast<AsmOpKind>(*op);
    goto *jumpTable[*op++];

    DO_MOV:; {
      reg[*op] = reg[*(++op)];
      op++;
      loopEnd;
    }

    DO_MOVI:; {
      auto& dest = reg[*op++];
      dest = derefCode<Object*>(*op);
      op += sizeof(Object*);
      loopEnd;
    }

    DO_ADD:;
    DO_MUL:; {
      calcObject(kind, reg[*op], reg[*(++op)]);
      op++;
      loopEnd;
    }

    DO_ADDI:; {

      loopEnd;
    }
    

  }

}