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
      &&DO_CMP,
      &&DO_CMPI,
      &&DO_ADD,
      &&DO_SUB,
      &&DO_MUL,
      &&DO_DIV,
      &&DO_ADDI,
      &&DO_SUBI,
      &&DO_MULI,
      &&DO_DIVI,
      &&DO_JUMP,
      &&DO_CALL,
    };

    auto op = code.begin();

  LOOP_BEGIN:;
    if( op == code.end() ) {
      return;
    }

    auto kind = static_cast<AsmOpKind>(*op);
    goto *jumpTable[*op++];

    DO_MOV: {
      reg[*op] = reg[*(++op)];
      op++;
      loopEnd;
    }

    DO_MOVI: {
      auto& dest = reg[*op++];
      dest = derefCode<Object*>(*op);
      op += sizeof(Object*);
      loopEnd;
    }

    DO_CMP:
    DO_CMPI:
      ;

    DO_ADD:
    DO_SUB:
    DO_MUL:
    DO_DIV: {
      calcObject(kind, reg[*op], reg[*(++op)]);
      op++;
      loopEnd;
    }

    DO_ADDI:
    DO_SUBI:
    DO_MULI:
    DO_DIVI: {
      calcObject(
          static_cast<AsmOpKind>(static_cast<u8>(kind) - 4),
          reg[op[0]],
          derefCode<Object*>(op[1])
        );

      op += sizeof(Object*) + 1;
      loopEnd;
    }

    DO_JUMP:
    DO_CALL:
      ;
    

  }

}