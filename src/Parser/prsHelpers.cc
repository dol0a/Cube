#include "Parser.h"
#include "Error.h"
#include "Utils.h"

namespace Cube {
  
  bool Parser::check() {
    return cur->kind != TOK_END;
  }

  void Parser::next() {
    cur = cur->next;
  }

  bool Parser::eat(std::wstring_view str) {
    if( cur->str == str ) {
      ate = cur;
      next();
      return true;
    }

    return false;
  }

  void Parser::expect(std::wstring_view str) {
    if( !eat(str) ) {
      Error::append(cur, "expected `%s`", Utils::Converter::to_string(str).c_str());
    }
  }

}