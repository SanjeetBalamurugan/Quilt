#pragma once

#include "pch.h"
#include "Events.h"
#include "core/KeyCodes.h"

namespace Quilt
{
  class Input;

  class KeyPressedEvent: public Event
  {
  private:
  KeyCode m_KeyCode = KeyCode::Unknown;
  static std::unordered_map<KeyCode, bool> s_KeyStates;

  friend class Input;
  public:
    explicit KeyPressedEvent(int keyCode)
      : m_KeyCode(static_cast<Quilt::KeyCode>(keyCode)) {
        s_KeyStates[m_KeyCode] = true;
    };
    KeyCode getKeyCode() const { return this->m_KeyCode; }
    EventType getEventType() const override { return EventType::KeyPressed; };
    static bool IsKeyPressed(KeyCode code)
    {
      return s_KeyStates[code];
    }

    static void ResetKeyState(KeyCode keyCode);
    static void UpdateKeyState(KeyCode key);
    static KeyCode GetCurrentKeyPressed();
  };
} // namespace Quilt
