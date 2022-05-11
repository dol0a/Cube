#include <iostream>
#include "VM.h"
#include "Object.h"

namespace Cube {
  void VM::callBuiltinFunc(size_t num) {
    switch( num ) {
      case 0: // print args[0]
        std::cout << args[0]->toString() << std::endl;
        break;
    }
  }
}