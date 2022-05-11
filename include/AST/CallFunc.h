#pragma once

namespace Cube::AST {
  struct CallFunc : Base {
    std::wstring_view name;
    std::vector<Base*> args;

    bool syscall = false;

    CallFunc() { kind = AST_CALLFUNC; }
  };
}