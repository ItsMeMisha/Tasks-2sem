#include "SFMLEngine.hpp"

namespace MyGraphics {

    Engine::Engine() = default;

    void Engine::initialize(const string& mainWindowName, const Vector2i& mainWindowSize) {
        mainWindow.create(sf::VideofMode(mainWindowSize.x, mainWindowSize.y), mainWindowName);
        renderTargets.push(&mainWindow);
    }

    void Engine::deinitialize() {
        mainWindow.close();
    }

    void Engine::display(Window* window) {
        window->handleEvent(EventType::DRAW);
    }

    void Engine::drawLine(const Vector2i& from, const Vector2i& to, const Color& color) {
        sf::VertexArray line(sf::Lines, 2);

        line[0].position = sf::Vector2f(from.x, from.y);
        line[0].color = sf::Color(color.getColor());

        line[1].position = sf::Vector2f(to.x, to.y);
        line[1].color = sf::Color(color.getColor());

        renderTargets.top()->draw(line);
    }

    void Engine::drawRectangle(const Vector2i& positioin, const Vector2i& size, const Color& color) {
        sf::RectangleShape rectangle;
        rectangle.setSize(sf::Vector2f(size.x, size.y));
        rectangle.setPosition(position.x, position.y);
        rectangle.setFillColor(sf::Color(color.getColor()));

        renderTargets.top()->draw(rectangle);
    }

    void Engine::drawImage(const Vector2i& position, const Image& image) {
    }

    void Engine::drawTexture(const Vector2i& position, const Texture& texture) {

    }

    void Engine::drawText(const Vector2i& position, const Text& text, const size_t size, const Color& color) {
        sf::Font font;
        font.loadFromFile(text.font);
        sf::Text sfText(text.text, font, size);
        sfText.setCharacterSize(size);
        sfText.setFillColor(color);
        sfText.setPosition(position.x, position.y);

        renderTargets.top()->draw(sfText);
    }

    Image Engine::loadImage(const std::string& path, Image& image) {
        sf::Image sfImage;
        sfImage.loadFromFile(path);

        sf::Vector2u size = sfImage.getSize();
        Image image({size.x, size.y}, Color(255, 255, 255, 255));

        for (int x = 0; x < size.x; ++x) 
            for (int y = 0; y < size.y; ++y) {
                sf::Color sfColor = sfImage.getPixel(x, y);
                image.setPixel(
                x, y, Color(sfColor.r, sfColor.g, sfColor.b, sfColor.a));
            }
        return image;
    }

    void saveImage(const Image& image, const std::string& path) {
        sf::Image sfImage;
        sfImage.create(image.getSize().x, image.getSize().y, sf::Color::Black);

        for (int x = 0; x < image.getSize().x; ++x) 
            for (int y = 0; y < image.getSize().y; ++y) 
                sfImage.setPixel(x, y, image.getPixel({x, y}));

        sfImage.saveToFile(path);
    }

    Event* Engine::pollEvent() {
        sf::Event event;
        if (!mainWindow.pollEvent(event)) return nullptr;
        return Engine::eventTranslator(event);
    }

    Event* Engine::eventTranslator(const sf::Event& event) {
        switch(event.type) {
            case (sf::Event::MouseButtonPressed):
            case (sf::Event::MouseButtonReleased):
                return mouseButtonEventTranslator(event);

            case (sf::Event::MouseMoved):
                return new MouseMoveEvent(Vector2i(event.mouseMove.x, event.mouseMove.y));

            case (sf::Event::KeyPressed):
                return keyEventTranslator(event.key);
            
        }
        return nullptr;

    }

    Event* Engine::mouseButtonEventTranslator(const sf::Event& event) {
        Vector2i position(event.mouseButton.x, event.mouseButton.y);

        MouseButtonEvent::Button button;
        switch(event.mouseButton.button):
            case (sf::Mouse::Button::Left):
                button = MouseButtonEvent::Button::LMB;
                break;

            case (sf::Mouse::Button::Right):
                button = MouseButtonEvent::Button::RMB;
                break;

            case (sf::Mouse::Button::Middle):
                button = MouseButtonEvent::Button::MMB;
                break;

            default:
                button = MouseButtonEvent::Button::UNDEFINED;

        MouseButtonEvent::state state = 
            event.type == sf::Event::MouseButtonPressed ?
                MouseButtonEvent::State::PRESSED :
                MouseButtonEvent::State::RELEASED;
        
        return new MouseButtonEvent(position, button, state);
    }

    Event* Engine::keyEventTranslator(const sf::Event::KeyEvent& event) {
        return new KeyPressedEvent(static_cast<KeyPressedEvent::Key>(event.code));
    }
}
