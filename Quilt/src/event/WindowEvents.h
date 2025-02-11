#pragma once

#include "pch.h"
#include "Events.h"

namespace Quilt
{
  class WindowResizeEvent: public Event
  {
  private:
  int m_Width = 0;
  int m_Height = 0;

  public:
  WindowResizeEvent(int width, int height)
    : m_Width(width), m_Height(height) {};

  int getWidth() {return this->m_Width;}
  int getHeight() {return this->m_Height;}
  EventType getEventType() const override { return EventType::WindowResize; };
  };

  class WindowCloseEvent: public Event
  {
  private:
    bool m_Closed = false;
  public:
    WindowCloseEvent(bool closed)
      : m_Closed(closed) {};
    
    bool IsWindowClosed() const { return this->m_Closed; }

    EventType getEventType() const override { return EventType::WindowClose; };
  };

  class WindowFocusEvent: public Event
  {
  private:
    bool m_Focused = false;
  public:
    WindowFocusEvent(bool Focused)
      : m_Focused(Focused) {};
    
    bool IsWindowFocusd() const { return this->m_Focused; }

    EventType getEventType() const override { return EventType::WindowFocus; };
  };
} // namespace Quilt
