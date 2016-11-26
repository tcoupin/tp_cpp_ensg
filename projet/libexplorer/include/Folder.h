#ifndef FOLDER_H
#define FOLDER_H

#include <vector>
#include "Element.h"

class Folder : public Element {
    public:
        Folder(std::string name, Folder* parent, std::string path);
        ~Folder();
        long int getSize();
        std::string toString();
        void addElement(Element* element);
        unsigned int countElement();
        Element* getElement(unsigned int i);
        void scan();

    protected:

    private:
        std::string path;
        std::vector<Element*> content;
        bool scanned;
        static bool compare(Element* a, Element*b);
};

#endif // FOLDER_H
