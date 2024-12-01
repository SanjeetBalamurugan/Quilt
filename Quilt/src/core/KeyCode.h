#pragma once

#include "pch.h"

namespace Quilt
{
  enum KeyCode {
    Space = GLFW_KEY_SPACE,


    Unknown = GLFW_KEY_UNKNOWN
  };

  inline KeyCode toKeyCode(int code) {
    return static_cast<KeyCode>(code);
  }
} // namespace Quilt