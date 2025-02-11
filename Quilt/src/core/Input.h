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
  };
} // namespace Quilt
