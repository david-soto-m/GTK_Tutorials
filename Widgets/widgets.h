#ifndef WIDGETS_H_
# define WIDGETS_H_

# include <gtkmm.h>

class Window : public Gtk::Window{
public:
    Window();
    virtual ~Window();
protected:
    Gtk::Label m_Label1;
    Gtk::Box m_VBox;
};

#endif // WIDGETS_H_

