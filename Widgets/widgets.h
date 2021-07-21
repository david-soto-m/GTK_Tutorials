#ifndef WIDGETS_H_
# define WIDGETS_H_

# include <gtkmm.h>

class Window : public Gtk::Window{
public:
    Window();
    virtual ~Window();
protected:
    void handle_entry_mod();
    void handle_entry_act();
    void handle_spin_mod();
    void handle_spin_act();

    Gtk::Label m_label1, m_label2, m_label_name;
    Gtk::Entry m_name_entry;
    Gtk::SpinButton m_spinny;
    Gtk::Box m_vbox, m_hbox;
};

#endif // WIDGETS_H_

