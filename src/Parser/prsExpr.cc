#include "Parser.h"
#include "Error.h"
#include "Utils.h"

namespace Cube {
  AST::Base* Parser::primary() {
    
    switch( cur->kind ) {

    }

    Error::append(cur, "invalid syntax");
    Error::crash();
  }

  AST::Base* Parser::mul() {
    
  }

  AST::Base* Parser::add() {
    
  }

}