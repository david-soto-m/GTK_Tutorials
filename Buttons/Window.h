#ifndef WINDOW_H_
#define WINDOW_H_

#include <gtkmm.h>
#include <string>

class Window : public Gtk::Window{
public:
    Window();
    virtual ~Window();
protected:
    bool status;

    bool expr1();
    bool expr2();

    std::string expr1_str = "a*b+c";
    std::string expr2_str = "a*(b+c)";

    void handle_but_clicked();

    void handle_tog_clicked();

    Gtk::Grid grid;

    Gtk::Label res_shower;

    Gtk::Button but;

    Gtk::ToggleButton tog;
    Gtk::CheckButton a,  b;

    Gtk::Box radio_box;
    Gtk::RadioButton::Group radio_group;
    Gtk::RadioButton rb_one;
    Gtk::RadioButton rb_two;
};

#endif  // WINDOW_H_
