#include "Application.h"

namespace Quilt
{
  Application::Application()
  {
    if (!glfwInit())
    {
      std::cerr << "Failed To Initialize GLFW!\n";
      exit(1);
    }
  }

  Application::~Application()
  {
  }

  void Application::CreateWindow(std::unique_ptr<Quilt::Window> window)
  {
    if (!window)
    {
      std::cerr << "Attempt to create null window!\n";
      return;
    }

    window->CreateWindow();
    this->m_windows.push_back(std::move(window));
  }

  void Application::run()
  {
    while (this->is_running)
    {
      for (auto it = this->m_windows.begin();
           it != this->m_windows.end();)
      {
        auto &window = *it;

        if (window->shouldClose())
        {
          window->DestroyWindow();
          it = this->m_windows.erase(it);
        }
        else
        {
          window->makeContextCurrent();
          glClear(GL_COLOR_BUFFER_BIT);
          window->swapBuffers();
          ++it;
        }

      }

      glfwPollEvents();

      if (this->m_windows.empty())
      {
        this->stop();
      }
    }
  }
} // namespace Quilt
