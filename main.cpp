#include <gtkmm.h>
#include "main_window.h"


int main(int argc, char *argv[]){
  Glib::RefPtr<Gtk::Application> app = Gtk::Application::create(argc,argv,"edu.uta.cse1325.example");

  Main_window win;

  win.set_title("MICE PROGRAM");

  return app->run(win);
}
