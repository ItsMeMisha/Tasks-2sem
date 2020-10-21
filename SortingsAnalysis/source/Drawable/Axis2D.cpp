#include "Axis2D.hpp"

namespace MyGUI {


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



}
