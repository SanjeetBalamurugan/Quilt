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
    window->SetEventCallback(std::bind(&Application::OnEvent, this, std::placeholders::_1));
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
          window->setIsWindowStarted(false);
          window->OnEnd();
          it = this->m_windows.erase(it);
        }
        else
        {
          if (!window->getIsWindowStarted())
          {
            window->OnStart();
            window->setIsWindowStarted(true);
          }
          

          window->makeContextCurrent();
          window->OnUpdate();

          glfwSetWindowSizeCallback(window->getWindow(), [](GLFWwindow* _window, int width, int height){
            Window::WindowData data = *(Window::WindowData*)glfwGetWindowUserPointer(_window);
            WindowResizeEvent e(width, height);
            data.m_width = width;
            data.m_height = height;

            data.callback(e);
          });

          glfwSetCursorPosCallback(window->getWindow(), [](GLFWwindow* _window, double xpos, double ypos){
            Window::WindowData data = *(Window::WindowData*)glfwGetWindowUserPointer(_window);
            MouseMoveEvent e(xpos, ypos);

            data.callback(e);
          });

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
