#pragma once
#include "pch.h"
#include "event/Events.h"
#include "event/WindowEvents.h"
#include "event/InputEvents.h"
#include "Window.h"

namespace Quilt
{
  class Application
  {
  private:
    bool m_Running = true;
    EventDispatcher m_Dispatcher;
    std::vector<std::unique_ptr<Quilt::Window>> m_Windows;

    void Init();
    void HandleWindows();
  public:
    Application() { this->Init(); };

    void Start();
    void Stop()
    {
      this->m_Running = false;
      glfwTerminate();
    }

    void RegisterWindow(std::unique_ptr<Quilt::Window> window);
    

    ~Application() {Stop();};
  };

} // namespace Quilt
