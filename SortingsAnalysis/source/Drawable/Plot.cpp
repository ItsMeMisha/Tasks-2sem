#ifndef __MY_GUI_PLOT_CPP
#define __MY_GUI_PLOT_CPP

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
}

#endif //__MY_GUI_PLOT_CPP
