#pragma once

#include <fstream>
#include <memory>
#include <vector>

namespace Cube::IO_Wrapper {
  class FileReader {
    std::unique_ptr<std::ifstream> ifs;
    
  public:
    FileReader() { }
    FileReader(std::string const& path);
    ~FileReader();

    std::wstring read_line();
    std::wstring read_all();
    std::vector<std::wstring> read_all_lines();
  };
}