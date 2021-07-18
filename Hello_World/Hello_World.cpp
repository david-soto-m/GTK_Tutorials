#include <gtkmm.h>
#include "./Window.h"

int main (int argc, char *argv[]) {
    auto app = Gtk::Application::create("org.gtkmm3.basic");
    Window mywin;
    return app->run(mywin, argc, argv);
}
