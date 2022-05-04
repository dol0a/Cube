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

  std::string to_string(std::wstring const& str) {
    return conv.to_bytes(str);
  }

  std::string to_string(std::wstring_view const& str) {
    return conv.to_bytes(std::wstring(str));
  }
}