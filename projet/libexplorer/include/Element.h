#ifndef ELEMENT_H
#define ELEMENT_H

#include <string>

// Exceptionnelement, on ne fait pas un include mais une simple
// déclaration pour éviter les appels en boucle
// (Element dépend de Folder qui dépend d'Element et...)
class Folder;


/**
\author Thibault Coupin
\brief Abstract class to represent an element of the file system
*/
class Element
{
    public:
        /**
            \brief Generic constructor
            \param name Element's name
            \param parent Folder containing the element, null if root
        */
        Element(std::string name, Folder* parent, std::string path);
        ~Element();
        Folder* getParent();
        std::string getName();
        virtual std::string toString() = 0;
        virtual long int getSize()=0;
        std::string getPrettySize();

    protected:
        std::string getPath();

    private:
        std::string name;
        std::string path;
        Folder* parent;
        static const char *unitLetter[];

};

#endif // ELEMENT_H

