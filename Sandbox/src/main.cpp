#include "Quilt.h"
#include "stdio.h"
#include <memory>

class MainWindow : public Quilt::Window
{
private:
  /* data */
public:
  MainWindow()
    : Quilt::Window(500, 500, "Sandbox") {};
  ~MainWindow() override = default;
};

class MainWindow2 : public Quilt::Window
{
private:
  /* data */
public:
  MainWindow2()
    : Quilt::Window(500, 500, "Sandbox2") {};
  ~MainWindow2() override = default;
};


class SandboxApplication : public Quilt::Application
{
private:
public:
  SandboxApplication()
    : Quilt::Application() {
      std::unique_ptr<MainWindow> window1 = std::make_unique<MainWindow>();
      std::unique_ptr<MainWindow2> window2 = std::make_unique<MainWindow2>();

      this->CreateWindow(std::move(window1));
      this->CreateWindow(std::move(window2));

      this->run();
    };

  void update() override {
    printf("Hello!");
    
  }
};

int main(int argc, char const *argv[])
{
  SandboxApplication app;
  return 0;
}
