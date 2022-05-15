#pragma once

namespace Cube {
  struct ObjString : Object {
    std::wstring value;

    std::string toString() const {
      return
        std::wstring_convert<std::codecvt_utf8<wchar_t>, wchar_t>()
        .to_bytes(value);
    }

    ObjString(std::wstring val = L"")
      : value(val)
    {
      type = TYPE_STRING;
    }

    ObjString(std::wstring_view v)
      : value(std::wstring(v))
    {
      type = TYPE_STRING;
    }
  };
}