#include "./Window.h"
#include <iostream>


Window::Window()
: m_button("Hello World") {
    m_button.set_border_width(10);
    m_button.signal_clicked().connect(
        sigc::mem_fun(
            *this,
            &Window::on_button_called
        )
    );
    add(m_button);
    m_button.show();
}

Window::~Window() {
}

void Window::on_button_called(){
    std::cout<<"Hello World\n";
}
