#include <iostream>
#include "Quilt.h"

class MainWindow : public Quilt::Window
{
private:
  /* data */
public:
  MainWindow()
      : Quilt::Window(500, 500, "HelloWorld") {};

  void OnWindowResizeEvent(Quilt::Event &event)
  {
    // Cast event to WindowResizeEvent
    if (event.getEventType() == Quilt::EventType::WindowResize)
    {
      auto &resizeEvent = static_cast<Quilt::WindowResizeEvent &>(event);
      std::cout << "Window resized: " << resizeEvent.getWidth() << "x" << resizeEvent.getHeight() << std::endl;
    }
  }

  void OnStart() override {};
  void OnUpdate() override
  {
    this->SetEventCallback([this](Quilt::Event &event)
                           { this->OnWindowResizeEvent(event); });
  };
  void OnEnd() override {};
};

int main()
{
  std::cout << "Works\n";
  std::unique_ptr<MainWindow> window = std::make_unique<MainWindow>();

  Quilt::Application app;
  app.RegisterWindow(std::move(window));

  app.Start();
  return 0;
}