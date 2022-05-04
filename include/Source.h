#pragma once

#include <map>
#include <string>

namespace Cube {
  class SourceRef {
    static inline std::map<std::wstring const*, SourceRef*> instanceMap;

    std::wstring const* source;
    size_t refCount;

    SourceRef() { }
    ~SourceRef() { }

  public:
    static SourceRef* getInstance(std::wstring const* src) {
      
    }


  };
}