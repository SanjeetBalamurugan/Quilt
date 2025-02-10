#include <iostream>
#include "Quilt.h"

class MainWindow : public Quilt::Window
{
private:
  /* data */
public:
  MainWindow()
      : Quilt::Window(500, 500, "HelloWorld") {};

  void OnEvent(Quilt::Event &event)
  {
    if (event.getEventType() == Quilt::EventType::WindowResize)
    {
      auto &resizeEvent = static_cast<Quilt::WindowResizeEvent &>(event);
      std::cout << "Window resized: " << resizeEvent.getWidth() << "x" << resizeEvent.getHeight() << std::endl;
    }

    if (event.getEventType() == Quilt::EventType::WindowClose)
    {
      std::cout << "Window Closed!" << std::endl;
    }

    if (event.getEventType() == Quilt::EventType::WindowFocus)
    {
      auto &focusEvent = static_cast<Quilt::WindowFocusEvent &>(event);
      if (focusEvent.IsWindowFocusd())
      {
        std::cout << "Window Focused!" << std::endl;
      }
      
    }
  }

  void OnStart() override {
  };
  void OnUpdate() override
  {
    this->SetEventCallback([this](Quilt::Event &event)
                           { this->OnEvent(event); });
  };
  void OnEnd() override {};
};

int main()
{
  std::cout << "Works\n";
  std::unique_ptr<MainWindow> window = std::make_unique<MainWindow>();
  std::unique_ptr<MainWindow> window1 = std::make_unique<MainWindow>();

  Quilt::Application app;
  app.RegisterWindow(std::move(window));
  app.RegisterWindow(std::move(window1));

  app.Start();
  return 0;
}