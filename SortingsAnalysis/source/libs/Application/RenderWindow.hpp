#ifndef __RENDER_WINDOW__
#define __RENDER_WINDOW__

#include "Window.hpp"

namespace MyGraphics {

    class RenderWindow : public Window {
    public:
        RenderWindow();
        RenderWindow(const Vector2i& position);

        Vector2i getPosition() const;
        void setPosition(const Vector2i& position);
        void handleEvent(Event* event) override;
        virtual void render() = 0;
    protected:
        Vector2i position;
    };
}

#endif //__RENDER_WINDOW__
