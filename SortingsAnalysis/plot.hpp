namespace MyGUI {

    const float Pi = 3.141592653589793238463;
    const float HalfPiInDegrees = 180f;

    float RadiansToDegrees (float angleInRadians);

    class Axis2D {

    public:
        Axis2D(sf::Vector2f pointFrom = {0.f, 0.f}, sf::Vector2f pointTo = {0.f, 0.f}, sf::Color color = sf::Color::White);
        
        draw(sf::RenderWindow& window);

    private:
        sf::Vertex line[2];
        sf::CircleShape arrowEnd(sizeOfArrowEnd, numOfTriangleVertexes);

        const float sizeOfArrowEnd = 5.f;
        const int numOfTriangleVertexes = 3;
        const float initRotationArrowEnd = HalfPiInDegrees / 3;
    };

    class Graph {
        Graph ();
        Graph (const int& numOfPoints, const sf::Vector2f* points, const sf::Vector2f zeroPos, const sf::Color& color = sf::Color::White);

        sf::Vertex* vertexes = nullptr;
        int numOfVertexes = 0;
        ~Graph ();        
    };
 
    class Plot2D {

    public:

        Plot2D();
        void draw();
        void setPosition(const float posX, const float posY);
        
        void setAxisOX(/*TODO*/);
        void setAxisOY(/*TODO*/);

        void pushGraph(/*TODO*/);
        void popGraph();
        void eraseAll();
        
    private:
        Axis2D axisOX;
        Axis2D axisOY;

        Graph* setOfGraphs; 
        int numOfGraphs;
        float scaleX = 1.f;
        float scaleY = 1.f;
    };

}
