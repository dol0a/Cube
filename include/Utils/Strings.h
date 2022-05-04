#pragma once

#include <vector>
#include <string>

namespace Utils::Strings {
  template <class Str, class Char = decltype(Str()[0])>
  void trim(std::vector<Str>& vec, Str const& str, Char sepalate) {
    size_t i, pos, len;

    for( i = 0, pos = 0, len = 0; i < str.length(); ) {
      if( str[i] == sepalate ) {
        vec.emplace_back(str.substr(pos, len));

        i++;
        pos = i;
        len = 0;
        continue;
      }

      i++;
      len++;
    }

    vec.emplace_back(str.substr(pos));
  }
}