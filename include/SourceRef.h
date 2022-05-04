#pragma once

#include <map>
#include <string>

namespace Cube {
  class SourceRef {
    static inline std::map<std::wstring const*, SourceRef*> instanceMap;

    std::wstring const* source;
    size_t refCount;

    SourceRef(std::wstring const* src)
      :source(src), refCount(0) { }

    ~SourceRef() { }

  public:
    static SourceRef* getInstance(std::wstring const* src) {
      auto& ptr = instanceMap[src];

      if( ptr == nullptr ) {
        ptr = new SourceRef(src);
      }

      return ptr;
    }

    std::wstring_view get_view(size_t pos, size_t len) const {
      return std::wstring_view(source->c_str() + pos, len);
    }

    bool isDeletable() {
      return refCount == 0;
    }

    bool Delete() { /* suicide */
      if( !isDeletable() )
        return false;
      
      delete this;
      return true;
    }
  };
}