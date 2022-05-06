#include <iostream>

#include "dbg.h"

#include "Lexer.h"
#include "Parser.h"
#include "Evaluater.h"
#include "Compiler.h"
#include "Assembler.h"
#include "VM.h"

#include "Utils.h"
#include "IO_Wrapper.h"
#include "SourceRef.h"
#include "Error.h"

using namespace Cube;

int test() {
  std::wstring_view s = L"abc\n123\naaa";

  std::vector<std::wstring_view> v;

  Utils::Strings::trim(v, s, L'\n');

  for(auto&&i:v){
    std::wcout << i << std::endl;
  }

  return 0;
}

void printToken(Token* token) {
  for( auto t = token; t->kind != TOK_END; t = t->next ) {
    std::cout << Utils::Converter::to_string(t->str) << std::endl;
  }
}

int main(int argc, char** argv) {
  
  IO_Wrapper::FileReader reader("test.txt");

  auto const&& src = reader.read_all();

  Lexer lexer{ src };

  auto token = lexer.lex();
  Error::check_strict();

  Parser parser{ token };

  auto ast = parser.parse();
  Error::check_strict();

  Evaluater eval;

  eval.eval(ast);
  Error::check_strict();

  Compiler compiler;
  compiler.compile(ast, 3);
  Error::check_strict();
  
  std::vector<u8> code;

  Assembler assembler{ code, compiler.get_oplist() };

  assembler.asm_full();
  Error::check_strict();

/*
  for( auto p = code.begin(); p != code.end(); p++ ) {
    printf("%02X\n", *p);
  }

alert;

  auto p1 = compiler.get_oplist()[0].object;
  auto p2 = derefCode<Object*>(code[2]);

  printf("%p\n", p1);
  printf("%p\n", p2);

  std::cout << p2->toString() << std::endl;
  */

  VM vm{ code };
  vm.run();

  

}