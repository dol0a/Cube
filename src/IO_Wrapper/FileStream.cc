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

    return ifs->is_open();
  }

  bool FileReader::read_line(std::wstring& out) {
    std::string tmp;

    if( std::getline(*ifs, tmp) ) {
      out = Utils::Converter::to_wstring(tmp);
      return true;
    }

    return false;
  }

  std::wstring FileReader::read_all() {
    std::string str;

    constexpr auto bufferSize = 1024;
    char buf[bufferSize];

    while( !ifs->eof() ) {
      ifs->read(buf, bufferSize);
      str.append(buf, ifs->gcount());
    }

    return Utils::Converter::to_wstring(str);
  }

  std::vector<std::wstring> FileReader::read_all_lines() {
    std::vector<std::wstring> ret;
    std::wstring tmp;

    while( read_line(tmp) ) {
      ret.emplace_back(tmp);
    }

    return ret;
  }
}