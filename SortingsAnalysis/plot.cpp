#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <cmath>
#include "plot.hpp"

namespace MyGUI {

    bool isEqualFloat (float val1, float val2) {

        return (val1 - val2 < epsilon || val2 - val1 < epsilon);
    }

    float RadiansToDegrees (float angleInRadians) {

        return angleInRadians * HalfPiInDegrees / Pi;
    }

    Axis2D::Axis2D (sf::Vector2f pointFrom, sf::Vector2f pointTo, sf::Color color) : 
        line ({sf::Vertex(pointFrom, color), sf::Vertex(pointTo, color)}) {

        arrowEnd.setFillColor (color);
        arrowEnd.setPosition (pointTo);

        arrowEnd.setRotation (initRotationArrowEnd);
        
        if (isEqual(pointFrom.x, pointTo.x))
            arrowEnd.setRotation (0);

        else arrowEnd.setRotation (RadiansToDegrees (atan ((pointTo.y - pointFrom.y) / (pointTo.x - pointFrom.x))));
    }

    
    Axis2D::draw(sf::RenderWindow& window) {

        window.draw (line, 2, sf::Lines);
        window.draw (arrowEnd);
    }

    Graph::Graph() : numOfVertexes (1), vertexes (new sf::Vertex) {}

    Graph::Graph(const int& numOfPoints, const sf::Vector2f* points, const sf::Vector2f zeroPos, const sf::Color& color) : 
        numOfVertexes (numOfPoints + 1), vertexes (new sf::Vertex[numOfVertexes]) {

        vertexes[0] = sf::Vertex(zeroPos, color);
        for (int i = 1; i < numOfVertexes; ++i)
            vertexes[i] = sf::Vertex(sf::Vector2f(points[i].x + zeroPos.x, points[i].y + zeroPos.y), color);
    }

}
