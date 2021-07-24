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
<span rise=\"10000\">of</span> a label <b>with</b> <tt>Centre</tt>\n\
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
    m_name_entry.set_max_length(50);
    m_name_entry.set_tooltip_text("It's super annoying, isn't it?");

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
    m_spinny.set_tooltip_markup(
"<tt>Numbers</tt> <b>don't</b> <i>make</i> <s>sense</s>");

    m_bar1.set_text("Progriss");
    m_bar1.set_show_text(true);
    m_bar1.set_direction(Gtk::TEXT_DIR_RTL);
    m_bar1.set_orientation(Gtk::ORIENTATION_HORIZONTAL);

    m_bar2.set_text("Name");
    m_bar2.set_show_text(true);
    m_bar2.set_pulse_step(1.0/double(m_name_entry.get_max_length()));

    m_label_ibar.set_text("You have reached maximum burrito capacity");
    auto ibar_cont = dynamic_cast<Gtk::Container*>(m_ibar.get_content_area());
    ibar_cont->add(m_label_ibar);
    m_ibar.add_button("_clear", 0);
    m_ibar.add_button("_unclear", 1);
    m_ibar.signal_response().connect(sigc::mem_fun(
        *this,
        &Window::handle_ibar_act
    ));
    m_ibar.set_message_type(Gtk::MESSAGE_ERROR);

    m_hbox.pack_start(m_spinny,Gtk::PACK_EXPAND_WIDGET);
    m_hbox.pack_start(m_bar1,Gtk::PACK_SHRINK);

    m_vbox.pack_start(m_ibar, Gtk::PACK_EXPAND_WIDGET);
    m_vbox.pack_start(m_label1, Gtk::PACK_EXPAND_WIDGET);
    m_vbox.pack_start(m_label2, Gtk::PACK_EXPAND_WIDGET);
    m_vbox.pack_start(m_name_entry, Gtk::PACK_EXPAND_WIDGET);
    m_vbox.pack_start(m_label_name, Gtk::PACK_EXPAND_WIDGET);
    m_vbox.pack_start(m_hbox, Gtk::PACK_EXPAND_WIDGET);
    m_vbox.pack_start(m_bar2, Gtk::PACK_EXPAND_WIDGET);


    add(m_vbox);
    show_all_children();
    m_ibar.hide();
}

Window::~Window(){
}

void Window::handle_entry_mod(){
    m_name_entry.set_visibility(! m_name_entry.get_visibility());
    m_bar2.pulse();
    if (m_name_entry.get_text_length() == m_name_entry.get_max_length()){
        m_ibar.show();
    }
}


void Window::handle_entry_act(){
    m_name_entry.set_editable(! m_name_entry.get_editable());
    m_label_name.set_text(m_name_entry.get_text());
    m_bar2.hide();
}

void Window::handle_spin_mod(){
    double step, page;
    m_spinny.get_increments(step, page);
    if (step>0.0001){
        m_spinny.set_increments(step/10.0,step/10.0);
    }
    double min, max;
    m_spinny.get_range(min, max);
    m_bar1.set_fraction((m_spinny.get_value()-min)/(max-min));
}

void Window::handle_spin_act(){
    m_label_name.set_text(std::to_string(m_spinny.get_value()));
    m_name_entry.set_editable(true);
    m_bar2.show();
}

void Window::handle_ibar_act(int id){
    switch (id){
        case 0:{
            m_label1.set_text(
"I wouldn't have got the lettuce if I knew it wouldn't fit");
            break;
        }
        case 1:{
            m_label2.set_text(
"I wouldn't have got the cheese if I knew it wouldn't fit");
            break;
        }
        default:{
            m_label1.set_markup("<big>Yo shouldn't be here</big>");
            break;
        }
    }
    Glib::ustring string = m_name_entry.get_text();
    int len = m_name_entry.get_text_length();
    m_name_entry.set_text(string.substr(0, int(len/2)));
    m_name_entry.set_editable(true);
    m_ibar.hide();
}
