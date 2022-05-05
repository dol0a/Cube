#pragma once

#include "Utils/Strings.h"
#include "Utils/Converter.h"

namespace Utils {
  template <class... Args>
  std::string format(char const* fmt, Args&&... args) {
    static char buf[0x1000];
    sprintf(buf, fmt, args...);
    return buf;
  }
}