#include <sstream>
#include <dirent.h>
#ifndef WIN32
    #include <sys/types.h>
#endif
#include "File.h"
#include "Folder.h"
#include <typeinfo>
#include <algorithm>
#include <iostream>


Folder::Folder(std::string name, Folder* parent, std::string path) : Element(name,parent, path), scanned(false)
{
}

Folder::~Folder()
{
    for (unsigned int i =0; i< content.size(); i++){
        delete content[i];
    }
}


long int Folder::getSize()
{
        return 0L;
}

std::string Folder::toString()
{
    std::stringstream ss;
    ss << "+\t\t" << getName();
    return ss.str();
}

void Folder::addElement(Element* element){
    content.push_back(element);
}

unsigned int Folder::countElement(){
    return content.size();
}

Element* Folder::getElement(unsigned int i){
    return content[i];
}

bool Folder::compare(Element* a, Element* b){
    if (a==0 || b ==0){
        return false;
    }
    bool a_isFolder = false;
    bool b_isFolder = false;
    std::string a_name, b_name;
    if (typeid(*a) == typeid(Folder)){
        a_isFolder = true;
    }
    if (typeid(*b) == typeid(Folder)){
        b_isFolder = true;
    }
    a_name = a->getName();
    b_name = b->getName();

    //Comparaison
    if (a_isFolder && b_isFolder || !a_isFolder && !b_isFolder){
        return a->getName() < b->getName();
    } else {
        return a_isFolder;
    }
}

void Folder::scan()
{
        if (scanned){
            return;
        }
        scanned = true;
        DIR* rep = NULL;
        struct dirent* fichierLu = NULL;
        std::string path = getPath();
        rep = opendir(path.c_str());

        Element* newElement;
        while ((fichierLu = readdir(rep)) != NULL){
            if (fichierLu->d_type == DT_REG){
                //Fichier
                newElement = new File(fichierLu->d_name, this, path+"/"+fichierLu->d_name);
                addElement(newElement);
            } else if (fichierLu->d_type == DT_LNK){
                //Lien
            } else if (fichierLu->d_type == DT_DIR){
                //Dossier
                newElement = new Folder(fichierLu->d_name,this, path+"/"+fichierLu->d_name);
                addElement(newElement);
            } else {
                //On ne fait rien
            }

        }
        std::sort(content.begin(), content.end(), Folder::compare);
}
