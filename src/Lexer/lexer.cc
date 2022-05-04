#include <string>
#include "Token.h"
#include "Lexer.h"

static wchar_t const* reservedTokens[] = {
  L"+",
  L"-",
  L"*",
  L"/"
};

namespace Cube {
  Token* Lexer::lex() {
    Token top{ TOK_END };
    Token* cur = &top;

    pass_space();

    while( check() ) {
      auto pos = position;
      auto ch = peek();
      size_t len;
      wchar_t const* str = source.c_str() + pos;

      if( isdigit(ch) ) {

      }
      else {
        for( std::wstring_view&& s : reservedTokens ) {
          
        }
      }

      pass_space();
    }

    cur = new Token(TOK_END, cur, position);
    return top.next;
  }
}