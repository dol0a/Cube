#include <iostream>
#include <vector>
#include "Error.h"
#include "SourceRef.h"

#define ERRLIST_MAX_SIZE  10
namespace Cube::Error {
  struct ErrorContext {
    SourceRef* srcref;

    size_t viewBegin, viewEnd;
    size_t errBegin, errEnd;

    std::string message;

    void print() const {
      printf("pos=%zu: %s\n", errBegin, message.c_str());
    }
  };

  namespace {
    std::vector<ErrorContext> ctx_list;
    char buf[0x1000];
  }

  void append(Token* token, char const* fmt, ...) {
    ErrorContext ctx = { 0 };

    va_list ap;
    va_start(ap, fmt);
    vsprintf(buf, fmt, ap);
    va_end(ap);

    ctx.srcref = token->src;
    ctx.errBegin = token->pos;
    ctx.errEnd = token->pos + token->str.length();
    ctx.message = buf;

    ctx_list.emplace_back(ctx);
  }

  void append(AST::Base* ast, char const* fmt, ...) {

  }

  void check() {
    if( ctx_list.size() >= ERRLIST_MAX_SIZE ) {
      view_all();
      crash();
    }
  }

  void view_all() {
    for( auto&& err : ctx_list ) {
      err.print();
    }
  }

  void crash() {
    view_all();
    exit(1);
  }
}