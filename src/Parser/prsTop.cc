#include "Parser.h"
#include "Error.h"
#include "Utils.h"

namespace Cube {

  AST::Base* Parser::top() {
    if( eat(L"fn") ) {
      auto ast = new AST::Function;
      ast->token = ate;
      
      expectIdent();
      ast->name = cur->str;

      next();
      expect(L"(");

      if( !eat(L")") ) {
        do {
          auto arg = new AST::Argument;

          expectIdent();
          arg->token = cur;
          arg->name = cur->str;

          expect(L":");
          arg->type = expectTypename();

          ast->args.emplace_back(arg);
        } while( eat(L",") );

        expect(L")");
      }

      if( eat(L"->") ) {
        ast->type = expectTypename();
      }

      ast->code = expectScope();

      return ast;
    }

    Error::append(cur, "expected function declare");
    Error::crash();
  }

}