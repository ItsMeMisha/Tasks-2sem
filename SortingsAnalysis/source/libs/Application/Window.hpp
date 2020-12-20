#ifndef __ABSTRACT_WINDOW__
#define __ABSTRACT_WINDOW__

#include "Event.hpp"

namespace MyGraphics {

    class Window {
    public:
        Window();
        virtual void handleEvent(const Event* event) = 0;
        virtual void addSubwindow(Window* subwindow);
        virtual ~Window();
    protected:
        std::vector<Window*> subwindows;
    };
}

#endif //__ABSTRACT_WINDOW__
