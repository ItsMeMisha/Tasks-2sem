#include "Window.hpp"

namespace MyGraphics {
    
    Window::Window() = default;

    void Window::addSubwindow(Window* subwindow) {
        subwindows.push_back(subwindow);
    }

    Window::~Window() {
        for (auto child : subwindows)
            delete child;
    }
}
