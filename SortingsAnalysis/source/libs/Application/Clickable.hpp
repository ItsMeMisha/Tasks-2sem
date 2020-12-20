#ifndef __CLICKABLE_HPP__
#define __CLICKABLE_HPP__

#include "Mouse.hpp"

namespace MyGraphics {

    class Clickable {
    public:
        virtual void handleMouseEvent(Event* event);
        virtual void handleMousePress(MouseButtonEvent* event) = 0;
        virtual void handleMouseRelease(MouseButtonEvent* event) = 0;
        virtual void handleMouseMove(MouseMoveEvent* event) = 0;
        virtual ~Clickable();
    };

}

#endif //__CLICKABLE_HPP__
