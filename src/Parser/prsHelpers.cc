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
      Error::crash();
    }
  }

  void Parser::expectIdent() {
    if( cur->kind != TOK_IDENT ) {
      Error::append(cur, "expected identifier");
      Error::crash();
    }
  }

  AST::Type* Parser::expectTypename() {
    auto ast = new AST::Type;

    expectIdent();
    ast->token = cur;
    ast->name = cur->str;

    next();

    if( eat(L"<") ) {
      do {
        ast->elems.emplace_back(expectTypename());
      } while( eat(L",") );

      if( cur->str == L">>" ) {
        cur->str = L">";
        cur->insert(L">");
      }

      expect(L">");
    }

    while( eat(L"[]") ) {
      ast->arr_depth++;
    }

    ast->reference = eat(L"&");

    return ast;
  }

  AST::Scope* Parser::expectScope() {
    expect(L"{");

    // if( !eat(L"}") )
    //   return nullptr;

    auto x = new AST::Scope;
    x->token = ate;
    
    while( check() && !eat(L"}") ) {
      x->list.emplace_back(expr());

      if( eat(L";") ) {
        if( eat(L"}") ) {
          x->list.emplace_back(nullptr);
          break;
        }

        continue;
      }

      // if( eat(L"}") ) {
      //   break;
      // }
    }

    return x;
  }


}