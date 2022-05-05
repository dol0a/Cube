#pragma once

namespace Cube {
  struct ObjLong : Object {
    int64_t value;

    std::string toString() const {
      return std::to_string(value);
    }

    ObjLong(int64_t val = 0)
      : value(val)
    {
      type = TYPE_LONG;
    }
  };
}