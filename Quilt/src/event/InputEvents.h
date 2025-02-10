#pragma once

#include "pch.h"
#include "Events.h"

namespace Quilt
{
  class KeyPressed: public Event
  {
  private:
  public:
    KeyPressed(){};
    EventType getEventType() const override { return EventType::KeyPressed; };
  };
} // namespace Quilt
