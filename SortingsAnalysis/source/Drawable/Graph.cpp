#include "Graph.hpp"

namespace MyGUI {

    Graph::Graph() : numOfVertexes (1), vertexes (new sf::Vertex) {}

    Graph::Graph(const int& numOfPoints, const sf::Vector2f* points, const sf::Vector2f zeroPos, const sf::Color& color) : 
        numOfVertexes (numOfPoints + 1), vertexes (new sf::Vertex[numOfVertexes]) {

        vertexes[0] = sf::Vertex(zeroPos, color);
        for (int i = 1; i < numOfVertexes; ++i)
            vertexes[i] = sf::Vertex(sf::Vector2f(points[i].x + zeroPos.x, points[i].y + zeroPos.y), color);
    }



}

