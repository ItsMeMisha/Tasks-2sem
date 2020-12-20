#ifndef __SFML_ENGINE_HPP__
#define __SFML_ENGINE_HPP__

#include <stack>
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Window/Event.hpp>

#include "Event.hpp"

namespace MyGraphics {

    class Engine {
    public:
        static void initialize(const string& mainWindowName, const Vector2i& mainWindowSize);
        static void deinitialize();
        
        static void display(Window* window);

        static void drawLine(const Vector2i& from, const Vector2i& to, const Color& color);
        static void drawRectangle(const Vector2i& positioin, const Vector2i& size, const Color& color);
        static void drawImage(const Vector2i& position, const Image& image);
        static void drawTexture(const Vector2i& position, const Texture& texture);
        static void drawText(const Vector2i& position, const Text& text, const size_t size, const Color& color);

        static Image loadImage(const std::string& path);
        static void saveImage(const Image& image, const std::string& path);

        static void pushTarget();
        

        static Event* pollEvent();
    private:
        Engine();

        static Event* eventTranslator(const sf::Event& event);
        static Event* mouseButtonEventTranslator(const sf::Event& event);
        static Event* keyEventTranslator(const sf::Event::KeyEvent& event);

        static sf::RenderWindow mainWindow;
        static std::stack<sf::RenderTarget*> renderTargets;
    };

}

#endif //__SFML_ENGINE_HPP__
