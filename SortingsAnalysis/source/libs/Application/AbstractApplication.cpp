#include "AbstractApplication.hpp"
//#include "EventQueue.hpp"
#include "Engine.hpp"

namespace MyGraphics {

    AbstractApplication::AbstractApplication() = default;
    
    void AbstractApplication::run() {
        running = true;
        Event* event = nullptr;

        while(running) {
            rootWindow->handleEvent(Engine::pollEvent());
            Engine::display(rootWindow);
        }
    }
}
