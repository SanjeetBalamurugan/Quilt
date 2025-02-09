#include "Application.h"

void Quilt::Application::Init()
{
  if (!glfwInit())
  {
    std::cerr << "GLFW Initialization Failed!" << std::endl;
    return;
  }

  glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
  glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
  glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
}

void Quilt::Application::HandleWindows()
{
  while (this->m_Running)
  {
    for (auto it = this->m_Windows.begin();
         it != this->m_Windows.end();)
    {
      auto &window = *it;

      if (window->ShouldClose())
      {
        window->Destroy();
        window->OnEnd();
        window->setWindowRunning(false);
        it = this->m_Windows.erase(it);
        continue;
      }

      if (window->isWindowRunning() == false)
      {
        //window->Create();
        window->OnStart();
        window->setWindowRunning(true);
      }

      window->MakeContextCurrent();
      window->OnUpdate();

      glClear(GL_COLOR_BUFFER_BIT);
      window->SwapBuffers();
      ++it;
    }

    glfwPollEvents();

    if (this->m_Windows.size() == 0)
    {
      Stop();
    }
  }
}

void Quilt::Application::Start()
{
  this->Init();
  this->HandleWindows();
}

void Quilt::Application::RegisterWindow(std::unique_ptr<Quilt::Window> window)
{
  if (!window)
  {
    std::cerr << "Attempt to create null window!\n";
    return;
  }

  window->Create();
  this->m_Windows.push_back(std::move(window));
}
