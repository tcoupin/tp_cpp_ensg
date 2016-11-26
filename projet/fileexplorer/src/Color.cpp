#include <sstream>
#include "Color.h"


std::string Color::text(color color, std::string text){
    // Voir https://en.wikipedia.org/wiki/ANSI_escape_code#Colors
    int code = color+30;
    std::stringstream ss;
    ss << "\033[1;" << code << "m" << text << "\033[0m\n";
    return ss.str();
}
