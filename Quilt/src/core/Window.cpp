#include "Window.h"

void Quilt::Window::Create()
{
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

void Quilt::Window::SetWindowColor(const char *hexCode, float alpha)
{
  if (hexCode[0] == '"')
    hexCode++;

  if (strlen(hexCode) != 6)
  {
    std::cerr << "Invalid hex code format! Expected 6 characters.\n";
    return;
  }

  int r, g, b;
  sscanf(hexCode, "%02x%02x%02x", &r, &g, &b);
  glClearColor(r / 255.0f, g / 255.0f, b / 255.0f, alpha);
}
