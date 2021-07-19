#include <Window.h>
#include <ranges.h>

int main(int argc, char *argv[]) {
    auto app = Gtk::Application::create();
    Window win;
    return app->run(win, argc, argv);
}
