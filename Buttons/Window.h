#ifndef WINDOW_H_
#define WINDOW_H_

#include <gtkmm.h>
#include <string>


class AbsExpr{
public:
    AbsExpr(std::string str = "hola");
    std::string expr_str, true_str = "True",  false_str = "False";

    virtual std::string expr_fun(bool a, bool b, bool c) = 0;

protected:
    ~AbsExpr(){};
};

class Expr1 : public AbsExpr{
public:
    Expr1(std::string str = "a*b+c");
    std::string expr_fun(bool a, bool b, bool c);
    virtual ~ Expr1(){};
};

class Expr2 : public AbsExpr{
public:
    Expr2(std::string str  = "a*(b+c)");
    std::string expr_fun(bool a, bool b, bool c);
    virtual ~ Expr2(){};
};


class Window : public Gtk::Window{
public:
    Window();
    virtual ~Window();
protected:
    bool status;

    Expr1 expr1;
    Expr2 expr2;

    void handle_but_clicked();

    void handle_tog_clicked();

    Gtk::Grid grid;

    Gtk::Label res_shower;

    Gtk::Button but;

    Gtk::ToggleButton tog;
    Gtk::CheckButton a,  b;

    Gtk::Box radio_box;
    Gtk::RadioButton::Group radio_group;
    Gtk::RadioButton rb_one;
    Gtk::RadioButton rb_two;
};
#endif  // WINDOW_H_
