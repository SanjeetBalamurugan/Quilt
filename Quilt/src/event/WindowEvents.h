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
} // namespace Quilt
