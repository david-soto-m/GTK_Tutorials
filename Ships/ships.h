#ifndef SHIPS_H_
# define SHIPS_H_

# include <gtkmm.h>

class Window : public Gtk::Window{

public:
    Window();
    virtual ~Window();

protected:
    Gtk::Label m_label1, m_label2, m_label3, m_label4, m_label5, m_label6;

    Gtk::Box m_box;
    Gtk::Frame m_frame;
    Gtk::Paned m_paned_frame;
    Gtk::Grid m_grid;
    Gtk::Notebook m_notebook;
    Gtk::ScrolledWindow m_scroll;

    Gtk::Button m_but1, m_but2, m_but3;
    Gtk::ButtonBox m_but_box;
};


#endif // SHIPS_H_
