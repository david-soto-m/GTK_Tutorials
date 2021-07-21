#include <widgets.h>
#include <string>

Window::Window():
m_vbox(Gtk::ORIENTATION_VERTICAL),
m_hbox(Gtk::ORIENTATION_HORIZONTAL)
{
    set_title("Widgets");
    set_border_width(10);

    m_label1.set_text(
        "Tis an example of a label with r\n justification");
    m_label1.set_justify(Gtk::JUSTIFY_RIGHT);
    m_label1.set_line_wrap(true);
    m_label1.set_line_wrap_mode(Pango::WRAP_WORD);

    m_label2.set_markup(
        "Tis an <span foreground=\"black\" background=\"white\">example</span>\
        <span rise=\"10000\">of</span> a label <b>with</b> <tt>Center</tt>\n\
        https://developer.gnome.org/pygtk/stable/pango-markup-language.html\n\
        https://docs.gtk.org/Pango/pango_markup.html\n\
        <big>justification</big>");
    m_label2.set_justify(Gtk::JUSTIFY_CENTER);
    m_label2.set_line_wrap(true);

    m_name_entry.set_text("Your name please");
    m_name_entry.signal_activate().connect(sigc::mem_fun(
        *this,
        &Window::handle_entry_act));
    m_name_entry.signal_changed().connect(sigc::mem_fun(
        *this,
        &Window::handle_entry_mod));

    m_label_name.set_justify(Gtk::JUSTIFY_CENTER);
    m_label_name.set_line_wrap(true);

    m_spinny.set_value(0);
    m_spinny.set_range(-1,1);
    m_spinny.set_increments(0.1, 0.1);
    m_spinny.set_digits(4);
    m_spinny.set_numeric(true);
    m_spinny.set_snap_to_ticks(true);
    m_spinny.signal_value_changed().connect(sigc::mem_fun(
        *this,
        &Window::handle_spin_mod
    ));
    m_spinny.signal_activate().connect(sigc::mem_fun(
        *this,
        &Window::handle_spin_act
    ));

    m_hbox.pack_start(m_spinny);

    m_vbox.pack_start(m_label1, Gtk::PACK_EXPAND_WIDGET);
    m_vbox.pack_start(m_label2, Gtk::PACK_EXPAND_WIDGET);
    m_vbox.pack_start(m_name_entry, Gtk::PACK_EXPAND_WIDGET);
    m_vbox.pack_start(m_label_name, Gtk::PACK_EXPAND_WIDGET);
    m_vbox.pack_start(m_hbox, Gtk::PACK_EXPAND_WIDGET);


    add(m_vbox);
    show_all_children();
}

Window::~Window(){
}

void Window::handle_entry_mod(){
    m_name_entry.set_visibility(! m_name_entry.get_visibility());
}


void Window::handle_entry_act(){
    m_name_entry.set_editable(! m_name_entry.get_editable());
    m_label_name.set_text(m_name_entry.get_text());
}

void Window::handle_spin_mod(){
    double step, page;
    m_spinny.get_increments(step, page);
    if (step>0.0001){
        m_spinny.set_increments(step/10.0,step/10.0);
    }
}

void Window::handle_spin_act(){
    m_label_name.set_text(std::to_string(m_spinny.get_value()));
    m_name_entry.set_editable(true);
}
