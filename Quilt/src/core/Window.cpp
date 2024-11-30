#include "Window.h"

void Quilt::Window::CreateWindow()
{
  m_window = glfwCreateWindow(this->m_width,
   this->m_height, this->m_title.c_str(), nullptr, nullptr);

  if (!m_window)
  {
    std::cerr << "Failed To Create Window!\n";
    glfwTerminate();
    exit(1);
  }
}

void Quilt::Window::DestroyWindow()
{
  glfwDestroyWindow(this->m_window);
}

void Quilt::Window::setSize(int width, int height)
{
  this->m_width = width;
  this->m_height = height;

  if (this->m_window)
  {
    glfwSetWindowSize(this->m_window,
     this->m_width, this->m_height);
  }
  
}

bool Quilt::Window::shouldClose()
{
  return true && glfwWindowShouldClose(this->m_window);
}

void Quilt::Window::swapBuffers()
{
  glfwSwapBuffers(this->m_window);
}

void Quilt::Window::makeContextCurrent()
{
  glfwMakeContextCurrent(this->m_window);
}
