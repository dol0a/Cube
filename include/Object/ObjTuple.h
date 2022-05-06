#pragma once

#include <vector>

namespace Cube {
  struct ObjTuple : Object {
    std::vector<Object*> list;

    std::string toString() const {
      std::string s;

      for( auto it = list.begin(); it != list.end(); it++ ) {
        s += (*it)->toString();
        if( it < list.end() - 1 ) s += ", ";
      }

      return "(" + s + ")";
    }

    ObjTuple() {
      type = TYPE_TUPLE;
    }
  };
}