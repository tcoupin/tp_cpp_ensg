#include <iostream>
#include <fstream>
#include "TableauDyn.h"

TableauDyn::TableauDyn(long int taille): nbmax(taille) , nbvalues(0) //: commenter pour faire planter le print et introduire le debug
{
    std::cout << "-- TableauDyn de taille:" << taille << std::endl;
    values = new float[nbmax]; // Attention à bien penser à faire un delete[]
}

TableauDyn::~TableauDyn()
{
    delete[] values;
    std::cout << "-- TableauDyn destruction" << std::endl;
}


TableauDyn::TableauDyn(const TableauDyn &source){
    nbmax = source.nbmax;
    nbvalues = source.nbvalues;
    values = new float[nbmax];
    for (int i = 0; i<nbvalues;i++){
        values[i] = source.values[i];
    }
}

void TableauDyn::print()
{
    std::cout << "---TableauDyn--" << std::endl;
    std::cout << "  - nbmax    : " << nbmax << std::endl;
    std::cout << "  - nbvalues : " << nbvalues << std::endl;
    std::cout << "  - values" << std::endl;
    for (long int i = 0 ; i< nbvalues ; i++){
        std::cout << "     - " << values[i] << std::endl;
    }
    std::cout << "  - sum      : " << sum() << std::endl;
    std::cout << "  - mean     : " << mean() << std::endl;
    std::cout << "-------------" << std::endl;
}

void TableauDyn::input()
{
    std::cout << "TableauDyn : à toi de bosser" << std::endl;
    for (long int i = 0;i<nbmax;i++){
        std::cout << "[" << i <<"]:";
        std::cin >> values[i];
        nbvalues++;
    }
}

float TableauDyn::sum()
{
    float sum;
    for (long int i = 0;i<nbvalues;i++){
        sum += values[i];
    }
    return sum;
}

float TableauDyn::mean()
{
    if (nbvalues == 0){
        return 0.0;
    }
    return sum()/nbvalues;
}

TableauDyn& TableauDyn::operator=(const TableauDyn& tab){
    delete[] values;
    nbmax = tab.nbmax;
    nbvalues = 0;
    return *this;
}


void TableauDyn::write(char* file)
{
    std::fstream fs;
    fs.open(file, std::fstream::out);
    fs << nbmax << std::endl << nbvalues << std::endl;
    for (int i = 0;i<nbvalues;i++){
        fs << values[i] << std::endl;
    }
    fs.close();
}

TableauDyn TableauDyn::read(char* file)
{
    std::fstream fs;
    fs.open(file, std::fstream::in);
    long int nbmax;
    fs >> nbmax;
    TableauDyn toreturn(nbmax);
    fs >> toreturn.nbvalues;
    for (int i = 0;i<toreturn.nbvalues;i++){
        fs >> toreturn.values[i];
    }
    fs.close();
    return toreturn;
}

void TableauDyn::writeb(char* file)
{
    std::fstream fs;
    fs.open(file, std::fstream::out|std::fstream::binary);
    fs.write((char*) &nbmax, sizeof(nbmax));
    fs.write((char*) &nbvalues, sizeof(nbvalues));
    for (int i = 0;i<nbvalues;i++){
        fs.write((char*) &values[i], sizeof(values[i]));
    }
    fs.close();
}

TableauDyn TableauDyn::readb(char* file)
{
    std::fstream fs;
    fs.open(file, std::fstream::in|std::fstream::binary);
    long int nbmax;
    fs.read((char*)&nbmax, sizeof(nbmax));
    TableauDyn toreturn(nbmax);
    fs.read((char*)&(toreturn.nbvalues), sizeof(toreturn.nbvalues));
    for (int i = 0;i<toreturn.nbvalues;i++){
        fs.read((char*)&(toreturn.values[i]), sizeof(toreturn.values[i]));
    }
    fs.close();
    return toreturn;
}
