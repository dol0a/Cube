#pragma once

namespace Cube {
  struct Object {
    TypeInfo type;
    size_t refCount;

  protected:
    Object()
      : type(TYPE_NONE),
        refCount(0)
    {
    }

    virtual ~Object() { }
  };
}