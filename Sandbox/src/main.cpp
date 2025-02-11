#include <iostream>
#include <optional>
#include "Quilt.h"

class MainWindow : public Quilt::Window
{
private:
  int prevX, prevY;
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
    if (Quilt::Input::IsKeyPressed(Quilt::KeyCode::A))
    {
      std::cout << "A Pressed\n";
    }

    if (auto key = Quilt::Input::GetCurrentKeyPressed(); key.has_value())
    {
      std::cout << Quilt::KeyCodeToString(*key);
    }
    
    if (Quilt::Input::GetMouseX() != this->prevX || Quilt::Input::GetMouseY() != this->prevY)
    {
        prevX = Quilt::Input::GetMouseX();
        prevY = Quilt::Input::GetMouseY();
        std::cout << "\nMouse X: " << prevX << ", Mouse Y: " << prevY << std::endl;
    }

    if (Quilt::Input::IsMouseKeyPressed(Quilt::MouseCode::MOUSE_BUTTON_LEFT))
    {
      std::cout << "LeftKey" << std::endl;
    }
    
    if (auto button = Quilt::Input::GetCurrentMouseKeyPressed(); button.has_value())
    {
      std::cout << Quilt::MouseCodeToString(*button) << std::endl;
    }
    
    this->SetEventCallback([this](Quilt::Event &event)
                           { this->OnEvent(event); });
  };
  void OnEnd() override {};
};

int main()
{
  std::cout << "Works\n";
  std::unique_ptr<MainWindow> window = std::make_unique<MainWindow>();
  //std::unique_ptr<MainWindow> window1 = std::make_unique<MainWindow>();

  Quilt::Application app;
  app.RegisterWindow(std::move(window));
  //app.RegisterWindow(std::move(window1));

  app.Start();
  return 0;
}