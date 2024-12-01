#pragma once

#include "pch.h"
#include "KeyCode.h"
#include "event/KeyEvent.h"

namespace Quilt
{
  class Input
  {
  private:
    GLFWwindow* m_window;
    KeyCode m_LastPressedKey;

    Input() {};
  public:
    Input(Input const&) = delete;
    void operator=(Input const&) = delete;

    static Input& getInstance() {
      static Input instance;
      return instance;
    }

    bool isKeyPressed(KeyCode code);

    friend class KeyPressedEvent;
  };
  
} // namespace Quilt
