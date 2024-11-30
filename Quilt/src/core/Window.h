#pragma once

#include "pch.h"

namespace Quilt
{
  class Window
  {
  protected:
    
  private:
    int m_width = 500;
    int m_height = 500;
    std::string m_title = "Example Quilt App";

    GLFWwindow* m_window;
  public:
    Window(int width, int height, std::string title)
      : m_width(width), m_height(height), m_title(title) {};

    void CreateWindow();
    void DestroyWindow();

    GLFWwindow* getWindow() { return this->m_window; }
    void setSize(int width, int height);
    bool shouldClose();
    void swapBuffers();
    void makeContextCurrent();

    virtual ~Window() = default;
  };
  
} // namespace Quilt
