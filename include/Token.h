#pragma once

#include <string>

namespace Cube {
  enum TokenKind {
    TOK_INT,
    TOK_FLOAT,
    TOK_CHAR,
    TOK_STRING,
    TOK_IDENT,
    TOK_RESERVED,
    TOK_END
  };

  class SourceRef;
  struct Token {
    TokenKind kind;
    Token* prev;
    Token* next;
    size_t pos;
    std::wstring_view str;
    SourceRef* src;

    Token* insert(std::wstring_view str) {
      auto tk = new Token(TOK_IDENT);
      tk->str = str;
      tk->pos = pos;
      tk->next = next;

      next = tk;

      return tk;
    }

    Token(TokenKind kind)
      : kind(kind),
        prev(nullptr),
        next(nullptr),
        pos(0),
        src(nullptr)
    {
    }

    Token(TokenKind kind, Token* prev, size_t pos)
      : Token(kind)
    {
      this->prev = prev;
      this->pos = pos;

      if( prev ) {
        prev->next = this;
      }
    }
  };
}