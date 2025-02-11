#include "InputEvents.h"

namespace Quilt
{
  std::unordered_map<KeyCode, bool> KeyPressedEvent::s_KeyStates;
  double MouseEvent::s_xpos;
  double MouseEvent::s_ypos;
  int MouseClickedEvent::s_button;
  int MouseClickedEvent::s_action;
  std::unordered_map<MouseCode, bool> MouseClickedEvent::s_ButtonStates;

  void KeyPressedEvent::ResetKeyState(KeyCode keyCode)
  {
    s_KeyStates[keyCode] = false;
  }

  void KeyPressedEvent::UpdateKeyState(KeyCode key)
  {
    KeyPressedEvent::s_KeyStates[key] = true;
  }

  KeyCode KeyPressedEvent::GetCurrentKeyPressed()
  {
    for (auto &state : s_KeyStates)
    {
      if (state.second)
      {
        KeyPressedEvent::ResetKeyState(state.first);
        return state.first;
      }
    }

    return KeyCode::Unknown;
  }

  double MouseEvent::GetMouseX() { return s_xpos; }
  double MouseEvent::GetMouseY() { return s_ypos; }
  std::optional<MouseCode> MouseClickedEvent::GetCurrentMouseKeyPressed()
  {
    for (auto& state: s_ButtonStates)
    {
      if (state.second)
      {
        MouseClickedEvent::SetButtonState(state.first, false);
        return state.first;
      }
    }
    
    return std::nullopt;
  }
}