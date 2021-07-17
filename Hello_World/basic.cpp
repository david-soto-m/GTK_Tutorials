# include <gtkmm.h>

class MyWin : public Gtk::Window{
    public:
        MyWin();
};

MyWin::MyWin() {
    set_title("Ya basic");
    set_default_size(200,200);
}

int main(int argc, char *argv[]) {
    auto app = Gtk::Application::create("org.gtkmm3.basic");
    MyWin mywin;
    return app->run(mywin, argc, argv);
}
