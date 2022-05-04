#pragma once

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

  struct Token {
    TokenKind kind;
    Token* prev;
    Token* next;
    size_t pos;
    std::wstring_view str;

    Token(TokenKind kind)
      : kind(kind),
        prev(nullptr),
        next(nullptr)
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