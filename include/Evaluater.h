#pragma once

#include <map>
#include "AST.h"
#include "TypeInfo.h"

#define  __ret_cache  \
  if( cache.contains(ast) ) return cache[ast];

#define  __reject_null  \
  if( !ast ) return { };

namespace Cube {

  class Evaluater {

    std::map<AST::Base*, TypeInfo> cache;

  public:
    Evaluater() { }

    TypeInfo eval(AST::Base* ast);

    TypeInfo evalExpr(AST::Base* ast);

  };

}