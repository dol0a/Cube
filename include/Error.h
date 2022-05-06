#pragma once

#include <cstdarg>
#include "AST.h"

namespace Cube {
  class Error {
    struct ErrorContext {
      SourceRef* srcref;

      size_t viewBegin, viewEnd;
      size_t errBegin, errEnd;

      std::string message;

      void print() const {
        printf("pos=%zu: %s\n", errBegin, message.c_str());
      }
    };

    static inline std::vector<ErrorContext> ctx_list;
    static inline char buf[0x1000];

  public:
    static void append(Token* token, char const* fmt, ...);
    static void append(AST::Base* ast, char const* fmt, ...);

    static void check();
    static void check_strict();
    
    static void view_all();
    
    [[noreturn]]
    static void crash();
  };
}