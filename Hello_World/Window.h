#ifndef WINDOW_H_
#define WINDOW_H_
#include <gtkmm/button.h>
#include <gtkmm/window.h>

class Window : public Gtk::Window {
public:
  Window();
  virtual ~Window();
protected:
  void on_button_called();
  Gtk::Button m_button;
};

#endif  // WINDOW_H_
