#include <string>
#include "Token.h"
#include "Lexer.h"

namespace Cube {
  bool Lexer::check() const {
    return position < source.length();
  }

  wchar_t Lexer::peek() const {
    return source[position];
  }

  bool Lexer::match(std::wstring_view str) const {
    if( position + str.length() <= source.length() ) {
      return source.substr(position, str.length()) == str;
    }

    return false;
  }

  size_t Lexer::count_num() {
    size_t len = 0;

    while( check() && isdigit(peek()) ) {
      len++, position++;
    }

    return len;
  }

  size_t Lexer::count_ident() {
    size_t len = 0;

    while( check() && (isalnum(peek()) || peek() == L'_') ) {
      len++, position++;
    }

    return len;
  }

  size_t Lexer::count_string(wchar_t begin) {
    size_t len = 0;

    if( peek() != begin )
      return 0;

    position++;
    while( check() && peek() != begin ) {
      len++, position++;
    }

    position++;
    return len;
  }

  void Lexer::pass_space() {
    while( check() && isspace(peek()) ) {
      position++;
    }
  }
}