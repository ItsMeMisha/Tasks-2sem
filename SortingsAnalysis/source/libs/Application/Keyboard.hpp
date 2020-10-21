#ifndef __APPLICATION_KEYBOARD__
#define __APPLICATION_KEYBOARD__


namespace Keyboard {

#ifdef __SFML_BUILD__

#include <SFML/Window/Keyboard.hpp>

    typedef sf::Keyboard::Key Key;

#endif //__SFML_BUILD__
}

#endif //__APPLICATION_KEYBOARD__
