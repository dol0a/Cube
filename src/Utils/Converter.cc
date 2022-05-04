#include <locale>
#include <codecvt>
#include "Utils/Converter.h"

namespace Utils::Converter {
  namespace {
    std::wstring_convert<std::codecvt_utf8<wchar_t>, wchar_t> conv;
  }

  std::wstring to_wstring(std::string const& str) {
    return conv.from_bytes(str);
  }
}