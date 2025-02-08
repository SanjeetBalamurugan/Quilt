#pragma once
#include "pch.h"
#include "event/Events.h"
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
    void RegisterWindow(std::unique_ptr<Quilt::Window> window);
    void Stop()
    {
      this->m_Running = false;
      glfwTerminate();
    }

    ~Application() {Stop();};
  };

} // namespace Quilt
