#pragma once

#include "pch.h"

namespace Quilt
{
  enum EventType {
    // Window Event
    WindowResize,

    // Mouse Events
    MouseMove
  };

  class Event
  {
  private:
    bool m_Handled = false;
  public:
    Event() = default;
    virtual ~Event() = default;

    virtual EventType getType() = 0;
    virtual const char* getName() const = 0;
    virtual std::string DebugPrint() const = 0;
  };

  class EventDispacher
  {
  template<typename T>
  using EventFn = std::function<bool(T&)>;

  private:
    Event& m_Event;
  public:
    EventDispacher(Event& event)
      : m_Event(event) {}

    template<typename T>
    bool Dispach(EventFn<T> func) {
      if (this->m_Event.getType() == T::getType())
      {
        m_Event.m_Handled = func(*(T&)m_Event);
        return true;
      }
      return false;
    }
  };  
  
} // namespace Quilt
