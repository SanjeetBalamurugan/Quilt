#pragma once

#include "pch.h"
#include "Window.h"
#include "event/WindowEvents.h"
#include "event/MouseEvent.h"

namespace Quilt
{
  class Application
  {
  private:
    bool is_running = true;
  
  protected:
  std::vector<std::unique_ptr<Quilt::Window>> m_windows = {};

  public:
    Application();
    virtual ~Application();
    void CreateWindow(std::unique_ptr<Quilt::Window> window);
    void run();
    void stop() {this->is_running = false;};

    void OnEvent(Event& event) {
      printf("%s", event.DebugPrint().c_str());
    };

    virtual void update() = 0;
  };
}