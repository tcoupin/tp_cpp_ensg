#include "File.h"
#include <sstream>
#include <fstream>


File::File(std::string name, Folder* parent, std::string path) : Element(name, parent, path)
{
    std::ifstream in(path.c_str(), std::ifstream::ate|std::ifstream::binary);
    size = in.tellg();
    in.close();
}

File::~File()
{
    //dtor
}


long int File::getSize()
{
        return size;
}

std::string File::toString()
{
    std::stringstream ss;
    ss << "-\t" << getPrettySize() << "\t" << getName();
    return ss.str();
}
