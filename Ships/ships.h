#ifndef SHIPS_H_
# define SHIPS_H_

# include <gtkmm.h>

class Window : public Gtk::Window{

public:
    Window();
    virtual ~Window();

protected:
    Gtk::Frame m_frame;
    Gtk::Label m_label_spread;
};


#endif // SHIPS_H_
