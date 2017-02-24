#include <gtkmm.h>
#include <HangMan.h>                              //connects HangManGui.cpp with HangMan.cpp
#include <Man.h>                                  //connects HangManGui.cpp with Man.cpp
                                                  //this creates a 400x250 window with HangMan as the title
int main(int argc, char** argv) {
  int WIDTH = 400;                                //sets the width of the pixel window to 400
  int HEIGHT = 250;                               //sets the height of the pixel window to 250
  Man mn;                                         //creates a variable in Hangman.cpp called man
  HangMan hm(mn, 1);                              // function in Hangman.cpp that sets the difficulty level
  auto app = Gtk::Application::create(argc, argv, //this prints a title for the window called HangMan
      "HangMan");
  Gtk::Window window;                             //this command will create the window where the game will be displayed
  window.set_default_size(WIDTH, HEIGHT);         // this sets the size of the window to the parameters set in line 6 and line 7

  return app -> run(window);                      //this will display the window


}
