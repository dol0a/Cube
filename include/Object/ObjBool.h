#pragma once

namespace Cube {
  struct ObjBool : Object {
    bool value;

    std::string toString() const {
      return value ? "true" : "false";
    }

    ObjBool(bool val = false)
      : value(val)
    {
      type = TYPE_BOOL;
    }
  };
}