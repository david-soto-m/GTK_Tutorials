#include <Window.h>
#include <gtkmm.h>

int main(int argc, char *argv[]) {
    auto app = Gtk::Application::create();
    Window win;
    return app->run(win, argc, argv);
}
