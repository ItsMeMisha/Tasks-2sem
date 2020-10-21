#ifndef __APPLICATION_MOUSE__
#define __APPLICATION_MOUSE__


namespace Mouse {

#ifdef __SFML_BUILD__

#include <SFML/Window/Mouse.hpp>

    typedef sf::Mouse::Button Button;

    struct Position {
        int x = 0;
        int y = 0;
    };

#endif //__SFML_BUILD__
}

#endif //__APPLICATION_MOUSE__
