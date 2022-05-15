#include "Assembler.h"
#include "Object.h"
#include "VM.h"

#include "dbg.h"

#define  _continue  goto LOOP_BEGIN
#define  _end goto LOOP_END

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
      nullptr,
      &&DO_SYSCALL,
      &&DO_PUSHARG,
    };

    //auto op = code.begin();
    auto op = &code[0];

  LOOP_BEGIN:;

    if( op == &code[0] + code.size() ) {
      return;
    }

    auto kind = static_cast<AsmOpKind>(*op);
    goto *jumpTable[*op++];

    DO_MOV: {
      reg[op[0]] = reg[op[1]];
      op += 2;
      _continue;
    }

    DO_MOVI: {
      auto& dest = reg[*op++];
      dest = derefCode<Object*>(*op);
      op += sizeof(Object*);
      _continue;
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
      _continue;
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
      _continue;
    }

    DO_JUMP:
    DO_CALL:
      op = derefCode<u8*>(*op);
      _continue;
    
    DO_RETURN:
      _end;
    
    DO_SYSCALL:
      callBuiltinFunc(*op++);
      _continue;

    DO_PUSHARG:
      args.emplace_back(reg[*op++]);
      _continue;

  LOOP_END:;
  }

}