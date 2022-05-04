#include "TypeInfo.h"

namespace Cube {
  bool TypeInfo::equals(TypeInfo const& type) const {
    return this->kind == type.kind;
  }
}