#include <trees.h>

Window::Window() :
m_paned_frame(Gtk::ORIENTATION_VERTICAL)
{
    set_title("Leaves from the vine");
    set_border_width(10);

    m_refListModel = Gtk::ListStore::create(m_Cols);
    m_list_tree.set_model(m_refListModel);

    Gtk::TreeModel::Row row;

    row = *(m_refListModel->append());
    row[m_Cols.m_Leaves] = 100;
    row[m_Cols.m_messg] = "Leaves from the vine";
    row = *(m_refListModel->append());
    row[m_Cols.m_Leaves] = 100;
    row[m_Cols.m_messg] = "Falling so slow";
    row = *(m_refListModel->append());
    row[m_Cols.m_Leaves] = 100;
    row[m_Cols.m_messg] = "Like fragile tiny shells";
    row = *(m_refListModel->append());
    row[m_Cols.m_Leaves] = 100;
    row[m_Cols.m_messg] = "Drifting in the foam";
    row = *(m_refListModel->append());
    row[m_Cols.m_Leaves] = 100;
    row[m_Cols.m_messg] = "Little soldier boy";
    row = *(m_refListModel->append());
    row[m_Cols.m_Leaves] = 100;
    row[m_Cols.m_messg] = "Come marching home";
    row = *(m_refListModel->append());
    row[m_Cols.m_Leaves] = 100;
    row[m_Cols.m_messg] = "Brave soldier boy";
    row = *(m_refListModel->append());
    row[m_Cols.m_Leaves] = 100;
    row[m_Cols.m_messg] = "Comes marching home";

    m_list_tree.append_column_editable("Leaves", m_Cols.m_Leaves);
    m_list_tree.append_column("Vines", m_Cols.m_messg);

    m_paned_frame.pack1(m_list_tree);

    m_refTreeModel = Gtk::TreeStore::create(m_Tree_Cols);
    m_tree_tree.set_model(m_refTreeModel);

    Gtk::TreeModel::Row childrow;

    row = *(m_refTreeModel->append());
    row[m_Tree_Cols.m_int] = 1;
    row[m_Tree_Cols.m_verse] = "Guru Lahima";
    childrow = *(m_refTreeModel->append(row.children()));
    childrow[m_Tree_Cols.m_int] = 11;
    childrow[m_Tree_Cols.m_verse] = "Let go of your earthly theher";
    childrow = *(m_refTreeModel->append(childrow.children()));
    childrow[m_Tree_Cols.m_int] = 12;
    childrow[m_Tree_Cols.m_verse] = "Empty the void";
    childrow = *(m_refTreeModel->append(childrow.children()));
    childrow[m_Tree_Cols.m_int] = 13;
    childrow[m_Tree_Cols.m_verse] = "Empty and become wind";
    row = *(m_refTreeModel->append());
    row[m_Tree_Cols.m_int] = 2;
    row[m_Tree_Cols.m_verse] = "Zaheer";
    childrow = *(m_refTreeModel->append(row.children()));
    childrow[m_Tree_Cols.m_int] = 31;
    childrow[m_Tree_Cols.m_verse] = "Have you ever read the poetry of the great airbending Guru, Laghima?";
    childrow = *(m_refTreeModel->append(row.children()));
    childrow[m_Tree_Cols.m_int] = 32;
    childrow[m_Tree_Cols.m_verse] = "The natural order, is disorder.";

    //Add the TreeView's view columns:
    m_tree_tree.append_column("number", m_Tree_Cols.m_int);
    m_tree_tree.append_column("Verse", m_Tree_Cols.m_verse);

    m_paned_frame.pack2(m_tree_tree);

    add(m_paned_frame);
    show_all_children();
}

Window::~Window(){
}

ListModelColumn::ListModelColumn(){
    add(m_Leaves);
    add(m_messg);
}

ListModelColumn::~ListModelColumn(){
}


TreeModelColumn::TreeModelColumn(){
    add(m_int);
    add(m_verse);
}

TreeModelColumn::~TreeModelColumn(){

}
