#ifndef FILE_H
#define FILE_H

#include "Element.h"


class File : public Element
{
    public:
        File(std::string name, Folder* parent, std::string path);
        ~File();
        long int getSize();
        std::string toString();

    protected:

    private:
        long int size;

};

#endif // FILE_H
