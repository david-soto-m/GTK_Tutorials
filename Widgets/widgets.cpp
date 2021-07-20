#include <widgets.h>

Window::Window():
m_V_Label_B(Gtk::ORIENTATION_VERTICAL)
{
    set_title("Widgets");

    add(m_V_Label_B);
}

Window::~Window(){
}
