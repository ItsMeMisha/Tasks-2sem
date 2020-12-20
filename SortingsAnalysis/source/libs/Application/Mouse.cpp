#include "Mouse.hpp"

namespace MyGraphics {

    MouseButtonEvent::MouseButtonEvent(const Vector2i& position, 
                                       const MouseButtonEvent::Button& button, 
                                       const MouseButtonEvent::State& state) :
        Event(EventType::MOUSE_BUTTON), position(position), button(button), state(state) {}

    MouseMoveEvent::MouseMoveEvent(const Vector2i& position) : 
        Event(EventType::MOUSE_MOVE), position(position) {}

}
