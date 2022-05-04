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

    void print() const {
      printf("");
    }
  };

  namespace {
    std::vector<ErrorContext> ctx_list;
  }

  void append(Token* token, char const* fmt, ...) {
    ErrorContext ctx = { 0 };

    ctx.srcref = token->src;
    ctx.errBegin = token->pos;
    ctx.errEnd = token->pos + token->str.length();

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