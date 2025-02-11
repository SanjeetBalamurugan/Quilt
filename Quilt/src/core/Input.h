#pragma once

#include "pch.h"
#include "event/InputEvents.h"
#include "KeyCodes.h"

namespace Quilt
{
  class Input
  {
  public:
    static bool IsKeyPressed(KeyCode code)
    {
      if (KeyPressedEvent::IsKeyPressed(code)) {
        KeyPressedEvent::ResetKeyState(code); 
        return true;
      }
      return false;
    }

    static std::optional<KeyCode> GetCurrentKeyPressed() {
      KeyCode currentKey = KeyPressedEvent::GetCurrentKeyPressed();
      if (currentKey != KeyCode::Unknown)
      {
        return currentKey;
      }
      
      return std::nullopt;
    }

    static double GetMouseX() { return MouseEvent::GetMouseX(); }
    static double GetMouseY() { return MouseEvent::GetMouseY(); }

    static bool IsMouseKeyPressed(MouseCode code)  {
      if (MouseClickedEvent::IsMouseKeyPressed(code))
      {
        MouseClickedEvent::SetButtonState(code, false);
        return true;
      }
      
      return false;
    }

    static std::optional<MouseCode> GetCurrentMouseKeyPressed() {
      return MouseClickedEvent::GetCurrentMouseKeyPressed();
    } 
  };
} // namespace Quilt
