#include <string>
#include "Utils.h"
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

    if( std::getline(*ifs, tmp) ) {
      return Utils::Converter::to_wstring(tmp);
    }

    return L"";
  }

  std::wstring FileReader::read_all() {
    return L"";
  }

  std::vector<std::wstring> FileReader::read_all_lines() {
    return { };
  }
}