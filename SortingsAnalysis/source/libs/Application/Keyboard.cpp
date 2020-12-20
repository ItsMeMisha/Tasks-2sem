#include "Keyboard.hpp"

namespace MyGraphics {

    KeyPressedEvent::KeyPressedEvent(const KeyPressedEvent::Key& key) :
        Event(EventType::KEY_PRESSED), key(key) {}

}
