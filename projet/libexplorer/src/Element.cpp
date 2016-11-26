#include "Element.h"
#include <sstream>

Element::Element(std::string name, Folder* parent, std::string path): name(name), parent(parent), path(path)
{

}

Element::~Element()
{

}

Folder* Element::getParent()
{
    if (parent != 0){
        return parent;
    } else {
        return (Folder*) this;
    }

}

std::string Element::getName()
{
    return name;
}

const char* Element::unitLetter[] = {
    "??",
    "o",
    "ko",
    "Mo",
    "Go",
    "To"
};

std::string Element::getPrettySize()
{
    long int sizeinunit = getSize();
    int unit = 1;
    while (sizeinunit > 1024){
        sizeinunit /= 1024;
        unit++;
    }
    std::stringstream ss;
    ss << sizeinunit;
    ss << " ";
    ss << unitLetter[unit];
    return ss.str();
}

std::string Element::getPath(){
    return path;
}
