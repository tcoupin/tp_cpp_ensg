#include <iostream>
#include "tabDyn2D.h"

tabDyn2D::tabDyn2D(int nbLignes, int nbCol):nbLignes(nbLignes),nbCol(nbCol){
    std::cout << "-- tabDyn2D de " << nbLignes << " lignes et " << nbCol << " colonnes" << std::endl;
    values = new double[nbLignes*nbCol]; // Attention à bien penser à faire un delete[]
}

tabDyn2D::~tabDyn2D(){
    delete[] values;
}

tabDyn2D::tabDyn2D(const tabDyn2D &source){
    nbLignes = source.nbLignes;
    nbCol = source.nbCol;
    values = new double[nbCol*nbLignes];
    for (int i = 0; i<nbCol*nbLignes;i++){
        values[i] = source.values[i];
    }
}

void tabDyn2D::affiche(){
    std::cout << "---tabDyn2D--" << std::endl;
    std::cout << "  - nbLignes    : " << nbLignes << std::endl;
    std::cout << "  - nbCol : " << nbCol << std::endl;
    std::cout << "  - values" << std::endl;
    for (long int i = 0 ; i< nbLignes*nbCol ; i++){
        std::cout << "     - " << values[i] << std::endl;
    }
    std::cout << "-------------" << std::endl;
}

tabDyn2D& tabDyn2D::operator=(const tabDyn2D& source){
    delete[] values;
    nbCol = source.nbCol;
    nbLignes = source.nbLignes;
    values = new double[nbCol*nbLignes];
    for (int i = 0; i<nbCol*nbLignes;i++){
        values[i] = source.values[i];
    }
    return *this;
}

tabDyn2D& tabDyn2D::operator+=(const tabDyn2D& source){
    //on considère que les matrices sont identiques
    for (int i = 0; i<nbCol*nbLignes;i++){
        values[i] += source.values[i];
    }
    return *this;
}

tabDyn2D& tabDyn2D::operator+=(const double value){
    for (int i = 0; i<nbCol*nbLignes;i++){
        values[i] += value;
    }
    return *this;
}
