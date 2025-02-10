#pragma once

#include "pch.h"


namespace Quilt
{
  enum class EventType {
      None = 0,
      WindowClose, WindowResize, WindowFocus,
      //KeyPressed, KeyReleased, MouseMoved, MouseClicked,
      //PhysicsStep, GameTick
  };
  
  class Event
  {
  public:
  virtual EventType getEventType() const = 0;
  virtual ~Event() = default;
  };

  class EventDispatcher
  {
  private:
  std::unordered_map<EventType, std::vector<std::function<void(Event&)>>> listeners;

  public:
  void subscribe(EventType type, std::function<void(Event&)> callback) {
    this->listeners[type].push_back(callback);
  }

  void dispatch(Event& event) {
    if (listeners.find(event.getEventType()) != listeners.end())
    {
      for (auto& callback:listeners[event.getEventType()])
      {
          callback(event);
      }
    }
  }
  };
} // namespace Quilt
