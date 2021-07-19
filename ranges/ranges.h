#ifndef RANGES_H_
#define RANGES_H_

#include <gtkmm.h>

class Window : public Gtk::Window{
public:
    Window();
    virtual ~Window();

protected:
    void handle_combo_pos();
    void handle_tog_clicked();
    void handle_adj2_val_mod();
    void handle_adj1_val_mod();

    Gtk::Box VTop, V2,VHScale;
    Gtk::Box HScales, HCombo, HDigits, HPageSize;

    Glib::RefPtr<Gtk::Adjustment> adj, adj_digits, adj_page

    Gtk::Scale Scale_V
};

#endif  // RANGES_H_
