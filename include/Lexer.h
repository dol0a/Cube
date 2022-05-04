#pragma once

namespace Cube {
  struct Token;
  class SourceRef;

  class Lexer {
    SourceRef* srcref;

    std::wstring const& source;
    size_t position;

    bool check() const;
    wchar_t peek() const;
    bool match(std::wstring_view str) const;

    size_t count_num();
    size_t count_ident();
    size_t count_string(wchar_t begin);

    void pass_space();

  public:
    explicit Lexer(std::wstring const& source);

    Token* lex();
  };
}