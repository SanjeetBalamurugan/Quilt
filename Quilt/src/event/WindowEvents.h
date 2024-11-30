#pragma once

#include "pch.h"
#include "Event.h"

namespace Quilt
{
  class WindowEvents : public Event
  {
  private:
    /* data */
  public:
    WindowEvents() = default;
    virtual ~WindowEvents() = default;

    virtual EventType getType() = 0;
    virtual const char* getName() const = 0;
    virtual std::string DebugPrint() const = 0;
  };

  class WindowResizeEvent : public WindowEvents
  {
  private:
    unsigned int m_width;
    unsigned int m_height;

  public:
    WindowResizeEvent(unsigned int width, unsigned int height)
      : m_width(width), m_height(height) {};
    ~WindowResizeEvent() override = default;

    EventType getType() override { return EventType::WindowResize; }
    const char* getName() const override { return "WindowResize"; };
    std::string DebugPrint() const {
      std::stringstream ss;

      ss << "\nWindowResize:\n" << "Width:" << this->m_width << "\nHeight:" << this->m_height ;
      return ss.str();
    }
  };
  
} // namespace Quilt
