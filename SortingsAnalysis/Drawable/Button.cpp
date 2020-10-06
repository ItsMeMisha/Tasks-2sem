#include <stdio.h>
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include "button.hpp"

namespace MyGUI {

        Button::Button (const Vector2f& position, const Vector2f& size, const char* text, const int textLength,
                const Color& fillColor, const Color& borderColor, const Color& textColor);


        void Button::setPosition (const Vector2f& position) {


        }

        void Button::setSize (const Vector2f& size) {


        }

        void Button::setFillColor (const Color& fillColor) {


        }

        void Button::setBorderColor (const Color& borderColor) {


        }

        void Button::setTextColot (const Color& textColor) {


        }

        void Button::setColors (const Color& fillColor, const Color& borderColor, const Color& textColor) {


        }

        bool Button::isMouseOn(const float mouseX, const float mouseY) {


        }    
    #ifdef __SFML_BUILD__
        virtual void Button::draw (sf::RenderTarget& target, sf::RenderStates states) const {


        }
    #endif

