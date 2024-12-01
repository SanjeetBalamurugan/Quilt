#include "Input.h"

namespace Quilt
{
  bool Input::isKeyPressed(KeyCode code) {
    return true ? code == this->m_LastPressedKey : false;
  }
} // namespace Quilt
