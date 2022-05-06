#pragma once

namespace Cube {
  struct ObjChar : Object {
    wchar_t value;

    std::string toString() const {
      return
        std::wstring_convert<std::codecvt_utf8<wchar_t>, wchar_t>()
        .to_bytes(std::wstring(1, value));
    }

    ObjChar(wchar_t val = 0)
      : value(val)
    {
      type = TYPE_CHAR;
    }
  };
}