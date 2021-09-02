#ifndef TREES_H_
# define TREES_H_

# include <gtkmm.h>

class ListModelColumn : public Gtk::TreeModel::ColumnRecord{
// This is a doc string
public:
    ListModelColumn();
    ~ListModelColumn();
    Gtk::TreeModelColumn<int> m_Leaves;
    Gtk::TreeModelColumn<Glib::ustring> m_messg;
};

class TreeModelColumn : public Gtk::TreeModel::ColumnRecord{
public:
    TreeModelColumn();
    ~TreeModelColumn();
    Gtk::TreeModelColumn<int> m_int;
    Gtk::TreeModelColumn<Glib::ustring> m_verse;
};

class Window : public Gtk::Window{
// Main window of the view
public:
    Window();
    virtual ~Window();
protected:
    Gtk::Paned m_paned_frame;
    Gtk::TreeView m_list_tree, m_tree_tree;
    ListModelColumn m_Cols;
    TreeModelColumn m_Tree_Cols;
    Glib::RefPtr<Gtk::ListStore> m_refListModel;
    Glib::RefPtr<Gtk::TreeStore> m_refTreeModel;
};
#endif // TREES_H_
