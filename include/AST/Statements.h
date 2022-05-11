#pragma once

namespace Cube::AST {
  struct If : Base {
    Base* condition;
    Base* trueCode;
    Base* falseCode;

    std::string toString() const { return ""; }

    If() { kind = AST_IF; }
  };
  
  struct For : Base {
    Base* init;
    Base* cond;
    Base* count;

    std::string toString() const { return ""; }

    For() { kind = AST_FOR; }
  };

  struct ForList : Base {
    Base* iterator;
    Base* arr;

    std::string toString() const { return ""; }

    ForList() { kind = AST_FOR_LIST; }
  };

  struct ForRange : Base {
    Base* iterator;
    Base* range;

    std::string toString() const { return ""; }

    ForRange() { kind = AST_FOR_RANGE; }
  };

  struct Loop : Base {
    Base* code;

    std::string toString() const { return ""; }

    Loop() { kind = AST_LOOP; }
  };

  struct While : Base {
    Base* cond;
    Base* code;

    std::string toString() const { return ""; }

    While() { kind = AST_WHILE; }
  };

  struct DoWhile : Base {
    Base* code;
    Base* cond;

    std::string toString() const { return ""; }

    DoWhile() { kind = AST_DOWHILE; }
  };
}