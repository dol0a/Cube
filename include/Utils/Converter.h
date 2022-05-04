#pragma once

#include <string>

namespace Utils::Converter {
  std::wstring to_wstring(std::string const&);
  std::string to_string(std::wstring const&);
  std::string to_string(std::wstring_view const&);
}