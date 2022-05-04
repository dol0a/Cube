#include <iostream>

#include "Lexer.h"
#include "Parser.h"
#include "Evaluater.h"
#include "Compiler.h"
#include "VM.h"

#include "Utils.h"
#include "IO_Wrapper.h"
#include "SourceRef.h"

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

int main(int argc, char** argv) {
  
  IO_Wrapper::FileReader reader("test.txt");

  auto const&& src = reader.read_all();

  



}