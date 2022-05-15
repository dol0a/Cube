#include <string>
#include "Token.h"
#include "Lexer.h"
#include "SourceRef.h"
#include "Error.h"

static wchar_t const* reservedIdentifiers[] = {
  L"fn",
  L"if",
  L"else",
  L"true",
  L"false",
  L"switch",
  L"case",
  L"while",
  L"for",
  L"loop",
  L"match",
  L"int",
  L"float",
  L"bool",
  L"char",
  L"string",
  L"tuple",
  L"class",
  L"struct",
  L"namespace",
  L"import",
  L"new",
};

static wchar_t const* reservedTokens[] = {
  L"<<=",
  L">>=",
  L"<<",
  L">>",
  L"+=",
  L"-=",
  L"*=",
  L"%=",
  L"/=",
  L"~=",
  L"^=",
  L"!=",
  L"[]",
  L"[",
  L"]",
  L"{",
  L"}",
  L"(",
  L")",
  L"=",
  L"+",
  L"-",
  L"%",
  L"*",
  L"/",
  L"@",
  L"&",
  L"'",
  L"$",
  L"#",
  L";",
  L":",
  L"?",
  L"^",
  L"~",
};

namespace Cube {
  Lexer::Lexer(std::wstring const& source)
    : source(source),
      position(0)
  {
    srcref = SourceRef::getInstance(&source);
  }

  Token* Lexer::lex() {
    Token top{ TOK_END };
    Token* cur = &top;

    pass_space();

    while( check() ) {
      auto pos = position;
      auto ch = peek();
      size_t len;
      wchar_t const* str = source.c_str() + pos;

      cur = new Token(TOK_INT, cur, pos);
      cur->src = srcref;

      if( isdigit(ch) ) {
        cur->str = { str, len = count_num() };

        if( peek() == L'.') {
          for( position++; isdigit(peek()); position++, len++ );
          cur->kind = TOK_FLOAT;
          cur->str = { str, len };
        }
      }
      else if( isalpha(ch) || ch == L'_' ) {
        cur->kind = TOK_IDENT;
        cur->str = { str, count_ident() };

        for( auto&& s : reservedIdentifiers ) {
          if( cur->str == s ) {
            cur->kind = TOK_RESERVED;
            break;
          }
        }
      }
      else if( ch == L'"' || ch == L'\'' ) {
        cur->kind = ch == L'"' ? TOK_STRING : TOK_CHAR;
        cur->str = { str, count_string(ch) };

        if( cur->kind == TOK_CHAR && cur->str.length() > 1 ) {
          Error::append(cur, "character literal is too long");
          Error::crash();
        }
      }
      else {
        for( std::wstring_view&& s : reservedTokens ) {
          if( match(s) ) {
            cur->kind = TOK_RESERVED;
            cur->str = s;
            position += s.length();
            goto found;
          }
        }

        Error::append(cur, "unknown token");
        Error::crash();
      found:;
      }

      pass_space();
    }

    cur = new Token(TOK_END, cur, position);
    return top.next;
  }
}