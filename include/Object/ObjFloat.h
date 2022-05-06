#pragma once

namespace Cube {
  struct ObjFloat : Object {
    double value;

    std::string toString() const {
      return std::to_string(value);
    }

    ObjFloat(double val = 0)
      : value(val)
    {
      type = TYPE_FLOAT;
    }
  };
}