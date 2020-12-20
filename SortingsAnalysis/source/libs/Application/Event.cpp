#include "Event.hpp"

namespace MyGraphics {
    Event::Event() : type(DEFAULT) {} 

    Event::Event(const EventType& type) : type(type) {}

    EventType Event::getType() const {
        return type;
    }

    Event::~Event() = default;
}
