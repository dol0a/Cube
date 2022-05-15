#include <iostream>
#include "VM.h"
#include "Object.h"

namespace Cube {
  void VM::callBuiltinFunc(size_t num) {
    switch( num ) {
      case 0: // print args[0]
        std::cout << args[0]->toString() << std::endl;
        popArg(1);
        break;
    }
  }

  void VM::popArg(int count) {
    for( int i = 0; i < count; i++ ) {
      args.pop_back();
    }
  }
}