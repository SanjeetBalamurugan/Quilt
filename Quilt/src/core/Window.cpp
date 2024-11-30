#include "Window.h"

void Quilt::Window::CreateWindow()
{
  m_window = glfwCreateWindow(this->data.m_width,
   this->data.m_height, this->data.m_title.c_str(), nullptr, nullptr);

  if (!m_window)
  {
    std::cerr << "Failed To Create Window!\n";
    glfwTerminate();
    exit(1);
  }

  glfwSetWindowUserPointer(this->m_window, &this->data);
}

void Quilt::Window::DestroyWindow()
{
  glfwDestroyWindow(this->m_window);
}

void Quilt::Window::setSize(int width, int height)
{
  this->data.m_width = width;
  this->data.m_height = height;

  if (this->m_window)
  {
    glfwSetWindowSize(this->m_window,
     this->data.m_width, this->data.m_height);
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

void Quilt::Window::OnStart()
{
}

void Quilt::Window::OnUpdate()
{
}

void Quilt::Window::OnEnd()
{
}
