#pragma once

#include "pch.h"
#include "event/Event.h"

namespace Quilt
{
  class Window
  {
  using EventCallbackFn = std::function<void(Event&)>;
    
  
  public:
  struct WindowData {
    unsigned int m_width = 500;
    unsigned int m_height = 500;
    std::string m_title = "Example Quilt App";
    
    EventCallbackFn callback;
  };

    Window(unsigned int width, unsigned int height, std::string title) {
      data.m_width = width;
      data.m_height = height;
      data.m_title = title;
    }

    void CreateWindow();
    void DestroyWindow();

    GLFWwindow* getWindow() { return this->m_window; }
    void setSize(int width, int height);
    bool shouldClose();
    void swapBuffers();
    void makeContextCurrent();

    bool getIsWindowStarted() const { return this->m_isWindowStarted; }
    void setIsWindowStarted(bool x) { this->m_isWindowStarted = x; }

    inline void SetEventCallback(const EventCallbackFn &func) { this->data.callback = func; };

    virtual void OnStart();
    virtual void OnUpdate();
    virtual void OnEnd();

    virtual ~Window() = default;

    private:
    WindowData data;
    GLFWwindow* m_window;

    bool m_isWindowStarted = false;
  };
  
} // namespace Quilt
