#include "RectangleWindow.hpp"

namespace MyGraphics {

    RectangleWindow::RectangleWindow() = default;
    RectangleWindow::RectangleWindow(const Vector2i& position, const Vector2i& size) :
        RenderWindow(position), size(size) {}

    Vector2i RectangleWindow::getSize() {
        return size;
    }

    void RectangleWindow::setSize(const Vector2i& size) {
        this->size = size;
    }

    bool RectangleWindow::isPointInside(const Vector2i& point) {

        return position.x <= point.x && 
               point.x <= position.x + size.x &&
               position.y <= point.y &&
               point.y <= position.y + size.y;
    }

}
