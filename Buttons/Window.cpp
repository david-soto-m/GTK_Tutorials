#include <Window.h>
#include <iostream>
#include <string>


Window::Window():
res_shower("Results will go here"),
but("evaluate"),
tog(expr1_str),
a("a"),
b("b"),
radio_box(Gtk::ORIENTATION_VERTICAL),
rb_one("True"),
rb_two("False")
{
    set_title("The logical Window");
    set_border_width(10);

    but.signal_clicked().connect(
        sigc::mem_fun(*this, &Window::handle_but_clicked)
    );

    tog.signal_clicked().connect(
        sigc::mem_fun(*this, &Window::handle_tog_clicked)
    );

    rb_one.set_group(radio_group);
    rb_two.set_group(radio_group);

    radio_box.add(rb_one);
    radio_box.add(rb_two);

    grid.attach(but, 1, 1);
    grid.attach(tog, 2, 1);
    grid.attach(a, 1, 2);
    grid.attach(b, 2, 2);
    grid.attach(radio_box,3, 2);
    grid.attach(res_shower, 1, 3, 2, 1);

    add(grid);
    show_all_children();
}
Window::~Window() {
}

void Window::handle_but_clicked(){
    res_shower.set_label(
        (tog.get_active() ? expr2() : expr1()) ? "True" : "False");
}

void Window::handle_tog_clicked(){
    tog.set_label(tog.get_active() ? expr2_str : expr1_str);

}

bool Window::expr1() {
    return (a.get_active()&&b.get_active())||rb_one.get_active();
}

bool Window::expr2() {
    return a.get_active()&&(b.get_active()||rb_one.get_active());
}
