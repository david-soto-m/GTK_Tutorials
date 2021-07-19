#include "./ranges.h"

ModelColumn::ModelColumn(){
    add(position_type);
    add(title);
}

Window::Window()
  :
    VTop(Gtk::ORIENTATION_VERTICAL, 0),
    V2(Gtk::ORIENTATION_VERTICAL, 20),
    VHScale(Gtk::ORIENTATION_VERTICAL, 10),
    HScales(Gtk::ORIENTATION_HORIZONTAL, 10),
    HCombo(Gtk::ORIENTATION_HORIZONTAL, 10),
    HDigits(Gtk::ORIENTATION_HORIZONTAL, 10),
    HPageSize(Gtk::ORIENTATION_HORIZONTAL, 10),
    adj(Gtk::Adjustment::create(0.0, 0.0, 101.0, 0.1, 1.0, 1.0)),
    adj_digits(Gtk::Adjustment::create(1.0, 0.0, 5.0, 1.0, 2.0)),
    adj_page(Gtk::Adjustment::create(1.0, 1.0, 101.0)),
    Scale_V(adj, Gtk::ORIENTATION_VERTICAL),
    Scale_H(adj, Gtk::ORIENTATION_HORIZONTAL),
    Scale_Digits(adj_digits),
    Scale_PageSize(adj_page),
    check("Display value on scale Widgets", 0),
    scroll(adj)
{
    set_title("Ranges");
    set_default_size(300, 500);

    Scale_V.set_digits(1);
    Scale_V.set_value_pos(Gtk::POS_TOP);
    Scale_V.set_draw_value();
    Scale_V.set_inverted();

    Scale_H.set_digits(1);
    Scale_H.set_value_pos(Gtk::POS_TOP);
    Scale_H.set_draw_value();

    add(VTop);
    VTop.pack_start(V2);
    V2.set_border_width(10);
    V2.pack_start(HScales);


    HScales.pack_start(Scale_V);
    HScales.pack_start(VHScale);

    VHScale.pack_start(Scale_H);


    VHScale.pack_start(scroll);


    check.set_active();
    check.signal_toggled().connect(sigc::mem_fun(*this,
        &Window::handle_tog));
    V2.pack_start(check, Gtk::PACK_SHRINK);



    refTreeModel = Gtk::ListStore::create(columns);
    combo_pos.set_model(refTreeModel);
    combo_pos.pack_start(columns.title);


    Gtk::TreeModel::Row row = *(refTreeModel->append());
    row[columns.position_type] = Gtk::POS_TOP;
    row[columns.title] = "Top";
    row = *(refTreeModel->append());
    row[columns.position_type] = Gtk::POS_BOTTOM;
    row[columns.title] = "Bottom";
    row = *(refTreeModel->append());
    row[columns.position_type] = Gtk::POS_LEFT;
    row[columns.title] = "Left";
    row = *(refTreeModel->append());
    row[columns.position_type] = Gtk::POS_RIGHT;
    row[columns.title] = "Right";

    V2.pack_start(HCombo, Gtk::PACK_SHRINK);
    HCombo.pack_start(
        *Gtk::make_managed<Gtk::Label>("Scale Value Position:", 0),
        Gtk::PACK_SHRINK);
    HCombo.pack_start(combo_pos);
    combo_pos.signal_changed().connect(
        sigc::mem_fun(
            *this,
            &Window::handle_combo_pos));
    combo_pos.set_active(0);


    HDigits.pack_start(
        *Gtk::make_managed<Gtk::Label>("Scale Digits:", 0), Gtk::PACK_SHRINK);
    Scale_Digits.set_digits(0);
    adj_digits->signal_value_changed().connect(sigc::mem_fun(*this,
        &Window::handle_adj1_val_mod));
    HDigits.pack_start(Scale_Digits);

    HCombo.pack_start(
        *Gtk::make_managed<Gtk::Label>("Scrollbar page size:", 0),
        Gtk::PACK_SHRINK);
    Scale_PageSize.set_digits(0);
    adj_page->signal_value_changed().connect(sigc::mem_fun(*this,
        &Window::handle_adj2_val_mod));
    HPageSize.pack_start(Scale_PageSize);

    V2.pack_start(HDigits, Gtk::PACK_SHRINK);
    V2.pack_start(HPageSize, Gtk::PACK_SHRINK);
    VTop.pack_start(sep, Gtk::PACK_SHRINK);

    show_all_children();
}

Window::~Window(){
}

void Window::handle_tog(){
    Scale_V.set_draw_value(check.get_active());
    Scale_H.set_draw_value(check.get_active());
}

void Window::handle_combo_pos(){
    Gtk::TreeModel::iterator iter = combo_pos.get_active();
    if(!iter)
    return;

    Gtk::TreeModel::Row row = *iter;
    if(!row)
    return;

    const Gtk::PositionType postype = row[columns.position_type];

    Scale_V.set_value_pos(postype);
    Scale_H.set_value_pos(postype);
}

void Window::handle_adj1_val_mod(){
    const double val = adj_digits->get_value();
    Scale_V.set_digits((int)val);
    Scale_H.set_digits((int)val);
}

void Window::handle_adj2_val_mod(){
    const double val = adj_page->get_value();
    adj->set_page_size(val);
    adj->set_page_increment(val);
}
