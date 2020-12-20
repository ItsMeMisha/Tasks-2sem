#ifndef __EVENT_HPP__
#define __EVENT_HPP__

#include "Data.hpp"

namespace MyGraphics {
    enum EventType {
        DEFAULT,
        WINDOW_CLOSED,
        MOUSE_BUTTON,
        MOUSE_MOVE,
        KEY_PRESSED,
        DRAW 
    };

    class Event {
    public:
        Event();
        Event(const EventType& type);
        virtual ~Event();
        
        EventType type;
    };
}

#endif //__EVENT_HPP__
