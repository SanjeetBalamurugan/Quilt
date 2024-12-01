#pragma once

#include <pch.h>
#include "Event.h"
#include "core/KeyCode.h"

namespace Quilt
{

  class Input;
  class KeyEvent : public Event
  {
  private:
    
  public:
    KeyEvent(/* args */) = default;
    virtual ~KeyEvent() = default;

    virtual EventType getType() = 0;
    virtual const char* getName() const = 0;
    virtual std::string DebugPrint() const = 0;
  };

  class KeyPressedEvent : public KeyEvent
  {
  private:
    Input* m_Input;
    int m_key;
  public:
    KeyPressedEvent(int key, int scancode, int action, int mods);
    ~KeyPressedEvent() override {};

    EventType getType() { return EventType::KeyPressed; };
    const char* getName() const { return "KeyPressed"; };
    std::string DebugPrint() const { return "KeyPressed" + std::to_string(m_key); };
  };
  
} // namespace Quilt
