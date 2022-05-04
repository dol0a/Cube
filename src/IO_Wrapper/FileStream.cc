#include <string>
#include "IO_Wrapper/FileStream.h"

namespace Cube::IO_Wrapper {
  FileReader::FileReader()
    : _isOpened(false),
      ifs(new std::ifstream)
  {
  }

  FileReader::FileReader(std::string const& path)
   : _isOpened(true),
      ifs(new std::ifstream(path))
  {
  }

  FileReader::~FileReader() {
    ifs->close();
    ifs.reset();
  }

  bool FileReader::open(std::string const& path) {
    ifs->open(path);
    _isOpened = true;
  }

  std::wstring FileReader::read_line() {
    std::string tmp;
    
  }

  std::wstring FileReader::read_all() {

  }

  std::vector<std::wstring> FileReader::read_all_lines() {

  }
}