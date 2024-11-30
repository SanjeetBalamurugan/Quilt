#pragma once

#include "pch.h"
#include "Event.h"

namespace Quilt
{
  class MouseEvent : public Event
  {
  private:
    /* data */
  public:
    MouseEvent() = default;
    virtual ~MouseEvent() = default;

    virtual EventType getType() = 0;
    virtual const char* getName() const = 0;
    virtual std::string DebugPrint() const = 0;
  };
  
  class MouseMoveEvent : public MouseEvent
  {
  private:
    float m_xpos;
    float m_ypos;
  public:
    MouseMoveEvent(float xpos, float ypos)
      : m_xpos(xpos), m_ypos(ypos) {};
    ~MouseMoveEvent() = default;

    EventType getType() { return EventType::MouseMove; };
    const char* getName() const { return "MouseMove"; };
    std::string DebugPrint() const {
      std::stringstream ss;

      ss << "MouseX: " << this->m_xpos << " MouseY: " << this->m_ypos << "\n";
      return ss.str();
    }
  };
  
} // namespace Quilt
