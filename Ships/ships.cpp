#include <ships.h>

Window::Window() :
m_box(Gtk::ORIENTATION_VERTICAL),
m_paned_frame(Gtk::ORIENTATION_VERTICAL),
m_but1("button 1 Does nothing"),
m_but2("button 2 Also does nothing"),
m_but3("button 3 is useless"),
m_but_box(Gtk::ORIENTATION_HORIZONTAL)
{
    set_title("Widgets");
    set_border_width(10);
    set_size_request(500, 300);

    m_box.set_homogeneous(true);
    m_box.set_spacing(30);

    m_label1.set_text("Hold up buttercup");
    m_label2.set_text("I guess it's never really over");
    m_label3.set_text("Just because it's over it doesn't mean it's really\
over");
    m_label4.set_text("Across the universe");
    m_label5.set_text("Hey Adora");
    m_label6.set_text("Hey Catra");

    m_frame.set_label("Hi fbi");
    // hor, Over Start Center End bellow
    m_frame.set_label_align(Gtk::ALIGN_END, Gtk::ALIGN_CENTER);
    m_frame.set_shadow_type(Gtk::SHADOW_NONE);
    m_frame.add(m_label1);
    m_box.pack_start(m_frame);

    m_paned_frame.pack1(m_label2);
    m_paned_frame.pack2(m_label3);
    m_box.pack_start(m_paned_frame);

    m_but_box.set_layout(Gtk::BUTTONBOX_SPREAD);
    m_but_box.add(m_but1);
    m_but_box.add(m_but2);
    m_box.pack_start(m_but_box);

    m_grid.attach(m_but3, 0, 0);
    m_grid.attach(m_label4, 1, 1);
    m_box.pack_start(m_grid);

    m_notebook.append_page(m_label5, "Bow");
    m_notebook.append_page(m_label6, "Glimmer");
    m_box.pack_start(m_notebook);

    m_scroll.set_policy(Gtk::POLICY_AUTOMATIC, Gtk::POLICY_AUTOMATIC);
    m_scroll.add(m_box);
    add(m_scroll);
    show_all_children();
}

Window::~Window(){
}
