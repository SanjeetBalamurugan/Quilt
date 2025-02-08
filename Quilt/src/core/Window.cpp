#include "Window.h"

void Quilt::Window::Create() {
  this->m_Window = glfwCreateWindow(this->m_Width, this->m_Height,
   this->m_Title.c_str(), nullptr, nullptr);

  if (!m_Window)
  {
    std::cerr << "Window '" << this->m_Title << "' failed to initialize!!!\n";
    exit(-1);
  } 
  glfwSetWindowUserPointer(m_Window, this);
}

void Quilt::Window::Destroy()
{
  glfwDestroyWindow(this->m_Window);
  this->m_Window = nullptr;
  this->m_Running = false;
}
