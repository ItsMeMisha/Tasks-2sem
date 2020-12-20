#include "RenderWindow.hpp"

namespace MyGraphics {

    RenderWindow::RenderWindow() = default;
    
    RenderWindow::RenderWindow(const Vector2i& position) : position(position) {}

    Vector2i RenderWindow::getPosition() {
        return position;
    }

    void RenderWindow::setPosition(const Vector2i& position) {
        this->position = position;
    }

    void RenderWindow::handleEvent(Event* event) {
        if (event->type == EventType::DRAW)
            render();

    }
}
