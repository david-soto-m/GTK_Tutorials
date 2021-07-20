#ifndef RANGES_H_
#define RANGES_H_

#include <gtkmm.h>

class ModelColumn: public Gtk::TreeModel::ColumnRecord{
public:
    ModelColumn();
    Gtk::TreeModelColumn<Gtk::PositionType> position_type;
    Gtk::TreeModelColumn<Glib::ustring> title;
};



class Window : public Gtk::Window{
public:
    Window();
    virtual ~Window();

protected:
    void handle_combo_pos();
    void handle_tog();
    void handle_adj2_val_mod();
    void handle_adj1_val_mod();

    Gtk::Box VTop, V2,VHScale;
    Gtk::Box HScales, HCombo, HDigits, HPageSize;

    // Smart pointers
    Glib::RefPtr<Gtk::Adjustment> adj, adj_digits, adj_page;

    Gtk::Scale Scale_V;
    Gtk::Scale Scale_H, Scale_Digits, Scale_PageSize;

    Gtk::Separator sep;

    Gtk::CheckButton check;

    Gtk::Scrollbar scroll;

    ModelColumn columns;

    Gtk::ComboBox combo_pos;

    Glib::RefPtr<Gtk::ListStore> refTreeModel;
};

#endif  // RANGES_H_
