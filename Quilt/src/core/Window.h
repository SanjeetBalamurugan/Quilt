#pragma once

#include "pch.h"

namespace Quilt
{
  class Window
  {
  private:
    GLFWwindow *m_Window = nullptr;

    int m_Width = 500;
    int m_Height = 500;
    std::string m_Title = "Default Window";

    bool m_IsVsync = false;
    bool m_Running = false;

  public:
    Window(int width, int height, std::string title)
        : m_Width(width), m_Height(height), m_Title(title) {};

    void Create();
    void Destroy();

    virtual void OnStart() = 0;
    virtual void OnUpdate() = 0;
    virtual void OnEnd() = 0;

    bool isVsync() const { return this->m_IsVsync; }
    void setVsync(bool isVsync) { this->m_IsVsync = isVsync; }

    bool isWindowRunning() const { return this->m_Running; }
    void setWindowRunning(bool isWindowRunning) { this->m_Running = isWindowRunning; }

    bool ShouldClose()
    {
      return glfwWindowShouldClose(this->m_Window);
    }

    void SwapBuffers()
    {
      glfwSwapBuffers(this->m_Window);
    }

    void MakeContextCurrent()
    {
      glfwMakeContextCurrent(this->m_Window);
    }

    GLFWwindow *getWindow() const { return this->m_Window; }

    virtual ~Window() = default;
  };

} // namespace Quilt
