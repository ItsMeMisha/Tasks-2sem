#include "RectangleButton.hpp"

namespace MyGraphics {

    RectangleButton::RectangleButton(const Vector2i& position, const Vector2i& size) :
        RectangleWindow(position, size) {};

    void RectangleButton::handleMouseEvent(Event* event) {
        if (event == nullptr)
            return;

        if (event->type == Event::EventType::MOUSE_BUTTON) {
            MouseButtonEvent* mouseEvent = dynamic_cast<MouseButtonEvent*>(event);

            if (mouseEvent.stat == MOuseButtonEvent::State::PRESSED)
                handleMousePress(mouseEvent);
            else handleMouseRelease(mouseEvent);

        } else 
            handleMouseMove(dynamic_cast<MouseMoveEvent>(event));
    }
}
