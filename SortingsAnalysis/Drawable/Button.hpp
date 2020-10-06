/*class Button : public sf::RectangleShape {

public:
    Button () = default; 
    Button (const float& posX, const float& posY, const float& sizeX, const float& sizeY, const sf::Color& color);

    void draw (sf::RenderWindow& window);
    bool mouseOn (float mousePosX, float mousePos);
    virtual void mainFunc ();
    void set (const float& posX, const float& posY, const float& sizeX, const float& sizeY, const sf::Color& color);

};
*/


namespace MyGUI {

    #define __SFML_BUILD__

    #ifdef __SFML_BUILD__
    using Rectangle = sf::RectangleShape;

    using Drawable = sf::Drawable;

    using Color = sf::Color;
    using Vector2f = sf::Vector2f;
    #endif

    class Button : public Drawable {

    public:

        Button (const Vector2f& position, const Vector2f& size, const char* text, const int textLength,
                const Color& fillColor, const Color& borderColor, const Color& textColor);
        void setPosition (const Vector2f& position);
        void setSize (const Vector2f& size);

        void setFillColor (const Color& fillColor);
        void setBorderColor (const Color& borderColor);
        void setTextColot (const Color& textColor);
        void setColors (const Color& fillColor, const Color& borderColor, const Color& textColor);       

        bool isMouseOn(const float mouseX, const float mouseY);
    
    #ifdef __SFML_BUILD__
        virtual void draw (sf::RenderTarget& target, sf::RenderStates states) const override;
    #endif
    private:
        Rectangle shape;
        char* text;
    };
}
