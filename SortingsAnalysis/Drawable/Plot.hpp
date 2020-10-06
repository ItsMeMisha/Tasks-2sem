#ifndef __MY_GUI_PLOT_HPP
#define __MY_GUI_PLOT_HPP

namespace MyGUI {

    #define __SFML_BUILD__

    #ifdef __SFML_BUILD__
    using Vector2f = sf::Vector2f;
    using Vertex = sf::Vertex;

    using Drawable = sf::Drawable;
    
    using Color = sf::Color;
    #endif

    const float Pi = 3.141592653589793238463;
    const float HalfPiInDegrees = 180f;

    float RadiansToDegrees (float angleInRadians);


    class Plot2D : public Drawable {

    public:

        Plot2D();
        virtual void draw(/*TODO*/) override;

        void setPosition (const Vector2f& position);
        void setPosition (const float posX, const float posY);
        
        void setAxisOX(/*TODO*/);
        void setAxisOY(/*TODO*/);

        void drawGraph(/*TODO*/);
        void hideGraph(/*TODO*/);
        void eraseAll();
        
    private:
        Axis2D axisOX;
        Axis2D axisOY;

        Graph* setOfGraphs; 
        int numOfGraphs;
        const int maxNumOfGraphs;
        Vector2f scale = {1f, 1f};
    };

}

#endif //__MY_GUI_PLOT_HPP
