#pragma once

#include <string>
#include <vector>

namespace Cube {
  enum TypeKind {
    TYPE_LONG,
    TYPE_FLOAT,
    TYPE_BOOL,
    TYPE_CHAR,
    TYPE_STRING,
    TYPE_TUPLE,
    TYPE_NONE
  };

  struct TypeInfo {
    static inline const std::wstring_view defaultTypeNames[] = {
      L"int",
      L"float",
      L"bool",
      L"char",
      L"string",
      L"tuple",
      L"none",
    };

    TypeKind kind;
    size_t arr_depth;
    bool reference;
    std::vector<TypeInfo> elems;

    std::wstring_view name;

    bool equals(TypeInfo const&) const;

    TypeInfo(TypeKind kind = TYPE_NONE)
      : kind(kind),
        arr_depth(0),
        reference(false)
    {
    }
  };
}