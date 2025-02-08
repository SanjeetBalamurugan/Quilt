#include <iostream>
#include "Quilt.h"

class MainWindow: public Quilt::Window
{
private:
  /* data */
public:
  MainWindow()
    : Quilt::Window(500, 500, "HelloWorld") {};

  void OnStart() override {};
  void OnUpdate() override {};
  void OnEnd() override {};
};

int main() {
  std::cout << "Works\n";
  std::unique_ptr<MainWindow> window = std::make_unique<MainWindow>();

  Quilt::Application app;
  app.RegisterWindow(std::move(window));

  app.Start();
  return 0;
}