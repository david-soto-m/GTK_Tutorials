#include <ships.h>

Window::Window(){
    set_title("Widgets");
    set_border_width(10);

    m_frame.set_label("Hi fbi");
    // hor, Over Start Center End bellow
    m_frame.set_label_align(Gtk::ALIGN_END, Gtk::ALIGN_CENTER);
    m_frame.set_shadow_type(Gtk::SHADOW_NONE);

    m_label_spread.set_text("Hold up buttercup");
    m_frame.add(m_label_spread);

    add(m_frame);

    show_all_children();
}

Window::~Window(){
}
