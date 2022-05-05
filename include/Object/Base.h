#pragma once

namespace Cube {
  struct Object {
    TypeInfo type;
    size_t refCount;

    virtual std::string toString() const = 0;

  protected:
    Object()
      : type(TYPE_NONE),
        refCount(0)
    {
    }

    virtual ~Object() { }
  };
}