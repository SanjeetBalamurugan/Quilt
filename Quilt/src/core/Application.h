#pragma once

#include "pch.h"
#include "Window.h"

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

    virtual void update() = 0;
  };
}