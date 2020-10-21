#ifndef __ABSTRACT_WINDOW__
#define __ABSTRACT_WINDOW__

#include "Keyboard.hpp"
#include "Mouse.hpp"

class Window {

public:
    virtual void handleKeyEvent(const Keyboard::Key& key);
    virtual void handleMouseClick(const Mouse::Button& button);
    virtual void handleMouseMove(const Mouse::Position& position);
    virtual void handleResize(int width, int height);
};

#endif //__ABSTRACT_WINDOW__
