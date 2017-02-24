#include <gtkmm.h>
#include <HangMan.h>
#include <Man.h>

int main(int argc, char** argv) {
  int WIDTH = 400;
  int HEIGHT = 250;
  Man mn;
  HangMan hm(mn, 1);
  auto app = Gtk::Application::create(argc, argv,
      "HangMan");
  Gtk::Window window;
  window.set_default_size(WIDTH, HEIGHT);

  return app -> run(window);


}
