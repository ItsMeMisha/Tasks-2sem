#ifndef __MY_GUI_AXIS2D_HPP
#define __MY_GUI_AXIS2D_HPP

namespace MyGUI {

    class Axis2D : public Drawable {

    public:
        Axis2D(Vector2f pointFrom = {0.f, 0.f}, Vector2f pointTo = {0.f, 0.f}, Color color = Color::White);
        
        virtual void draw(sf::RenderWindow& window) override;

    private:
        Vertex line[2];
        sf::CircleShape arrowEnd(sizeOfArrowEnd, numOfTriangleVertexes);

        const float sizeOfArrowEnd = 5.f;
        const int numOfTriangleVertexes = 3;
        const float initRotationArrowEnd = HalfPiInDegrees / 3;
    };

}

#endif //__MY_GUI_GRAPH_HPP
