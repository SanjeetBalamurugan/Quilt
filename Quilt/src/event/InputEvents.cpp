#include "InputEvents.h"

namespace Quilt
{
  std::unordered_map<KeyCode, bool> KeyPressedEvent::s_KeyStates;

  void KeyPressedEvent::ResetKeyState(KeyCode keyCode)
  {
    s_KeyStates[keyCode] = false;
  }

  void KeyPressedEvent::UpdateKeyState(KeyCode key) {
    KeyPressedEvent::s_KeyStates[key] = true;
  }

  KeyCode KeyPressedEvent::GetCurrentKeyPressed() {
    for (auto& state: s_KeyStates)
    {
      if (state.second)
      {
        KeyPressedEvent::ResetKeyState(state.first);
        return state.first;
      }
    }
    
    return KeyCode::Unknown;
  }
}