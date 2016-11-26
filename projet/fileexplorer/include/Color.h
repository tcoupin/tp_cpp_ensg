#ifndef COLOR_H
#define COLOR_H

#include <string>

namespace Color
{
    enum color {
        BLACK,
        RED,
        GREEN,
        YELLOW,
        BLUE,
        MAGENTA,
        CYAN,
        WHITE
    };

    std::string text(color color, std::string text);
};

#endif // COLOR_H
