#ifndef __APPLICATION_MOUSE__
#define __APPLICATION_MOUSE__

#include "Event.hpp"

namespace MyGraphics {

    class MouseButtonEvent : public Event {
    public:
        enum Button {
            UNDEFINED = 0,
            LMB = 1,
            MMB = 2,
            RMB = 3
        };

        enum State {
            PRESSED = 0,
            RELEASED = 1
        }:

        MouseButtonEvent(const Vector2i& position, const Button& button, const State& state);
        const Vector2i position;
        const Button button;
        const State state;
    };

    class MouseMoveEvent : public Event {
    public:
        MouseMoveEvent(const Vector2i& position);
        const Vector2i position;
    }
}

#endif //__APPLICATION_MOUSE__
