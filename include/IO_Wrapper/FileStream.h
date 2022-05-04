#pragma once

#include <fstream>
#include <memory>
#include <vector>

namespace Cube::IO_Wrapper {
  class FileReader {
    bool _isOpened;
    std::unique_ptr<std::ifstream> ifs;
    
  public:
    FileReader();
    FileReader(std::string const& path);
    ~FileReader();

    bool open(std::string const& path);

    bool read_line(std::wstring& out);
    std::wstring read_all();
    std::vector<std::wstring> read_all_lines();
  };
}