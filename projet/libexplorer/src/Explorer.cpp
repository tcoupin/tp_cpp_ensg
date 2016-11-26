#include "Explorer.h"
#include <string>
#include <sstream>
#include <vector>
#include <iostream>
#include <typeinfo>

Explorer::Explorer(std::string rootPath)
{
    rootFolder = new Folder("root", 0, rootPath);
    currentFolder = rootFolder;
    rootFolder->scan();
}

Explorer::~Explorer()
{
    delete rootFolder;
}

std::string Explorer::pwd(){
    std::vector<std::string> pathElement;
    Folder* ousuisje = currentFolder;
    while (ousuisje != rootFolder){
        pathElement.push_back(ousuisje->getName());
        ousuisje = ousuisje->getParent();
    }
    std::stringstream ss;
    for (int i = (pathElement.size()-1); i>=0; i--){
        ss << "/" << pathElement[i];
    }

    // Quand mm un / pour le root
    if (pathElement.size() == 0){
        ss << "/";
    }

    return ss.str();
}

void Explorer::ls(){
    for (int i = 0; i< currentFolder->countElement();i++){
        std::cout << currentFolder->getElement(i)->toString() << std::endl;
    }
}

void Explorer::cd(std::string dir){
    if (".." == dir){
        currentFolder = currentFolder->getParent();
        return;
    }
    if ("." == dir){
        return;
    }
    Folder* newFolder = 0;
    for (int i = 0; i<currentFolder->countElement(); i++){
        if (typeid(*(currentFolder->getElement(i))) == typeid(*(rootFolder))){
            if (currentFolder->getElement(i)->getName() == dir){
                newFolder = (Folder*) currentFolder->getElement(i);
                break;
            }
        }
    }
    if (newFolder==0){
        throw std::string("Dossier inconnu !");
    }
    currentFolder = newFolder;
    currentFolder->scan();
}
