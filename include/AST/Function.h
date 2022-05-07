#pragma once

namespace Cube::AST {
  struct Function : Base {
    std::wstring_view name;
    Type* type;
    Base* code;
    std::vector<Argument*> args;

    Function()
      : type(nullptr),
        code(nullptr)
    {
      kind = AST_FUNCTION;
    }
  };
}