#ifndef __RECTANGLE_WINDOW_HPP__
#define __RECTANGLE_WINDOW_HPP__

#include "RenderWindow.hpp"

namespace MyGraphics {
 
    class RectangleWindow : public RenderWindow {
    public:
        RectangleWindow();
        RectangleWindow(const Vector2i& position, const Vector2i& size);

        virtual void render() override;
        Vector2i getSize() const;
        void setSize(const Vector2i size);

        bool isPointInside(const Vector2i& point);
    protected:
        Vector2i size;
    };
}

#endif //__RECTANGLE_WINDOW_HPP__
