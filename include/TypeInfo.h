#pragma once

#include <string>

namespace Cube {
  enum TypeKind {
    TYPE_INT,
    TYPE_FLOAT,
    TYPE_BOOL,
    TYPE_CHAR,
    TYPE_STRING,
    TYPE_NONE
  };

  struct TypeInfo {
    TypeKind kind;

    std::wstring_view name;

    bool equals(TypeInfo const&) const;

    TypeInfo(TypeKind kind = TYPE_NONE)
      : kind(kind)
    {
    }
  };
}