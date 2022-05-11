#pragma once

namespace Cube::AST {
  struct ScopeResolution : Base {
    std::vector<std::wstring_view> names;

    ScopeResolution() {
      kind = AST_SCOPE_RESOLUTION;
    }
  };
}