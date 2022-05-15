#pragma once

#include <iostream>

#define  DEBUG  1

#if DEBUG
  #define  alert  fprintf(stderr,"\t#alert %s:%d\n",__FILE__,__LINE__)
  #define  debug(...)  __VA_ARGS__
#else
  #define  alert  0
  #define  debug(...)  0;
#endif

