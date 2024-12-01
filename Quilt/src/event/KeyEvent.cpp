#include "KeyEvent.h"
#include "core/Input.h"

Quilt::KeyPressedEvent::KeyPressedEvent(int key, int scancode, int action, int mods)
  : m_Input(&Input::getInstance())
{
  switch (action)
  {
  case GLFW_PRESS:
    this->m_Input->m_LastPressedKey = toKeyCode(key);
    break;
  case GLFW_RELEASE:
    if (this->m_Input->m_LastPressedKey == key)
    {
      this->m_Input->m_LastPressedKey = toKeyCode(GLFW_KEY_UNKNOWN);
    }
    
    break;
  
  default:
    break;
  }
}