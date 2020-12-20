#ifndef __RECTANGLE_BUTTON_HPP_
#define __RECTANGLE_BUTTON_HPP_

#include "RectangleWindow.hpp"
#include "Clickable.hpp"

namespace MyGraphics {

    class RectangleButton : public RectangleWindow, public Clickable.hpp {
    public:
        RectangleButton(const Vector2i& position, const Vector2i& size);
        void handleMouseEvent(Event* event) override;
    };
}

#endif //__RECTANGLE_BUTTON_HPP__
