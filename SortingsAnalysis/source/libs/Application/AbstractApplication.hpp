#ifndef __ABSTRACT_APPLICATION__
#define __ABSTRACT_APPLICATION__

#include "Window.hpp"

namespace MyGraphics {

    class AbstractApplication {
    public:
        virtual static void initialize() = 0;
        virtual static void run();
        virtual static void deinitialize() = 0;
    
    protected:
        static bool running;
        static Window* rootWindow;
        AbstractApplication();
    };
}

#endif //__ABSTRACT_APPLICATION__
