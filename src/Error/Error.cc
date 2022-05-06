#include <iostream>
#include <vector>
#include "Error.h"
#include "SourceRef.h"

#define ERRLIST_MAX_SIZE  10
namespace Cube {
  
  void Error::append(Token* token, char const* fmt, ...) {
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

  void Error::append(AST::Base* ast, char const* fmt, ...) {
    append(ast->token, "append with AST not yet implemented");
  }

  void Error::check() {
    if( ctx_list.size() >= ERRLIST_MAX_SIZE ) {
      view_all();
      
      std::cerr
        << std::endl
        << "compiler crashed due to previous many errors" << std::endl;

      crash();
    }
  }

  void Error::check_strict() {
    if( !ctx_list.empty() ) {
      view_all();
      crash();
    }
  }

  void Error::view_all() {
    for( auto&& err : ctx_list ) {
      err.print();
    }
  }

  void Error::crash() {
    view_all();
    exit(1);
  }
}