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
      &&DO_RETURN,
    };

    //auto op = code.begin();
    auto op = &code[0];

  LOOP_BEGIN:;

    // alert;
    // fprintf(stderr,"*op = %02X\n", *op);

    if( op == &code[0] + code.size() ) {
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
      calcObject(kind, reg[op[0]], reg[op[1]]);
      op += 2;
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
      op = derefCode<u8*>(*op);
      loopEnd;
    
    DO_RETURN:
      ;

  }

}