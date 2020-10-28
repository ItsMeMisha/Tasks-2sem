#ifndef __WINDOWS_MANAGER__
#define __WINDOWS_MANAGER__

#include "Window.hpp"

class WindowsManager : public Window {

public:
    void handleKeyEvent(const Keyboard::Key& key) override;
    void handleMouseClick(const Mouse::Button& button) override;
    void handleMouseMove(const Mouse::Position& position) override;
    void handleResize(int width, int height) override;

    void addWindow(Window* newWindow);

private:

    void callbackKeyEvent(const Keyboard::Key& key);
    void callbackMouseClick(const Mouse::Button& button);
    void callbackMouseMove(const Mouse::Position& position);
    void callbackResize(int width, int height);
    vector<Window*> windows;
};

#endif //__WINDOWS_MANAGER__
