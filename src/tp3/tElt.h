#ifndef TELT_H
#define TELT_H

#include <iostream>

template <typename T>
class tElt
{
    public:
        tElt(long int taille);
        tElt(const tElt &source);
        ~tElt();
        void print();

    protected:

    private:
        long int nbmax;
        T* values;
        long int nbvalues;
};

template <typename T>
tElt<T>::tElt(long int taille): nbmax(taille) , nbvalues(0)
{
    std::cout << "-- tElt de taille:" << taille << std::endl;
    values = new T[nbmax]; // Attention à bien penser à faire un delete[]
}

template <typename T>
tElt<T>::~tElt()
{
    delete[] values;
}

template <typename T>
tElt<T>::tElt(const tElt &source){
    nbmax = source.nbmax;
    nbvalues = source.nbvalues;
    values = new T[nbmax];
    for (int i = 0; i<nbvalues;i++){
        values[i] = source.values[i];
    }
}

template <typename T>
void tElt<T>::print()
{
    std::cout << "---TableauDyn--" << std::endl;
    std::cout << "  - nbmax    : " << nbmax << std::endl;
    std::cout << "  - nbvalues : " << nbvalues << std::endl;
    std::cout << "  - values" << std::endl;
    for (long int i = 0 ; i< nbvalues ; i++){
        std::cout << "     - " << values[i] << std::endl;
    }
    std::cout << "-------------" << std::endl;
}

#endif // TELT_H_INCLUDED
