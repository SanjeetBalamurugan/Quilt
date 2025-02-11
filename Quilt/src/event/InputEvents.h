#pragma once

#include "pch.h"
#include "Events.h"
#include "core/KeyCodes.h"

namespace Quilt
{
  class Input;

  class KeyPressedEvent : public Event
  {
  private:
    KeyCode m_KeyCode = KeyCode::Unknown;
    static std::unordered_map<KeyCode, bool> s_KeyStates;

    friend class Input;

  public:
    explicit KeyPressedEvent(int keyCode)
        : m_KeyCode(static_cast<Quilt::KeyCode>(keyCode))
    {
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

  class MouseEvent : public Event
  {
  private:
    static double s_xpos;
    static double s_ypos;

  public:
    explicit MouseEvent(double xpos, double ypos)
    {
      s_xpos = xpos;
      s_ypos = ypos;
    };

    static double GetMouseX();
    static double GetMouseY();

    EventType getEventType() const override { return EventType::MousePos; };
  };

  class MouseClickedEvent : public Event
  {
  private:
    static int s_button;
    static int s_action;
    static std::unordered_map<MouseCode, bool> s_ButtonStates;

  public:
    explicit MouseClickedEvent(int button, int action)
    {
      s_button = button;
      s_action = action;
      s_ButtonStates[static_cast<MouseCode>(button)] = true;
    };

    static int GetButton() { return s_button; }
    static int GetAction() { return s_action; }

    static bool IsMouseKeyPressed(MouseCode code) {
      return s_ButtonStates[code];
    }
    static void SetButtonState(MouseCode button, bool t) {
      s_ButtonStates[button] = t;
    }

    static std::optional<MouseCode> GetCurrentMouseKeyPressed();

    EventType getEventType() const override { return EventType::MouseClicked; };
  };
} // namespace Quilt
