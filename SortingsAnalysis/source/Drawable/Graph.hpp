#ifndef __MY_GUI_GRAPH_HPP
#define __MY_GUI_GRAPH_HPP

namespace MyGUI {

    class Graph : public Drawable {

    public:
        Graph ();
        Graph (const int& numOfPoints, const Vector2f* points, const Vector2f zeroPos, const Color& color = Color::White);

        Graph (const Graph& other);
        Graph (Graph&& other);

        ~Graph ();

        virtual void draw(sf::RenderWindow& window) override;

    private: 
        Vertex* vertexes = nullptr;
        int numOfVertexes = 0;
    };
 

}

#endif //__MY_GUI_GRAPH_HPP
