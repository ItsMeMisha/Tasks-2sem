#include "Clickable.hpp"

namespace MyGraphics {

    Clickable::handleMouseEvent(Event* event) {
        if (event->getType() == EventType::MOUSE_MOVE) {
            handleMouseMove(dynamic_cast<MouseMoveEvent*> (event));
            return;
        }

        if (event->getType() != EventType::MOUSE_BUTTON)
            return;

        MouseButtonEvent mouseEvent = dynamic_cast<MouseButtonEvent*> (event);

        if (mouseEvent->state == MouseButtonEvent::State::PRESSED)
            handleMousePress(mouseEvent);

        else handleMouseRelease(mouseEvent);
    }

}
