#include "Tableau.h"
#include <iostream>

Tableau::Tableau() : nbvalues(0)
{
    std::cout << "Tableau : création" << std::endl;
}

Tableau::~Tableau()
{
    std::cout << "Tableau : extermination" << std::endl;
}

void Tableau::push(float value) {
    if (nbvalues == nbmax){
        std::cout << "Tableau : je suis rempli" << std::endl;
        return;
    }
    values[nbvalues++] = value; // On met le ++ après la valeur pour que l'indice soit la valeur actuelle puis on l'incrémente
    // values[++nbvalues] = value; // on commencerai à remplire à la case 1 alors que ça commence à 0
}

float Tableau::sum() {
    float sum;
    for (long int i = 0;i<nbvalues;i++){
        sum += values[i];
    }
    return sum;
}

float Tableau::mean(){
    if (nbvalues == 0){
        return 0.0;
    }
    return sum()/nbvalues;
}

void Tableau::input(){
    std::cout << "Tableau : à toi de bosser" << std::endl;
    for (long int i = 0;i<nbmax;i++){
        std::cout << "[" << i <<"]:";
        std::cin >> values[i];
        nbvalues++;
    }
}

void Tableau::pushUnsecure(float value) {
    values[nbvalues++] = value;
}

void Tableau::print(){
    std::cout << "---Tableau--" << std::endl;
    std::cout << "  - nbmax    : " << nbmax << std::endl;
    std::cout << "  - nbvalues : " << nbvalues << std::endl;
    std::cout << "  - values" << std::endl;
    for (long int i = 0 ; i< nbvalues ; i++){
        std::cout << "     - " << values[i] << std::endl;
    }
    std::cout << "-------------" << std::endl;
}
void Tableau::printAll(){
    std::cout << "---Tableau--" << std::endl;
    std::cout << "  - nbmax    : " << nbmax << std::endl;
    std::cout << "  - nbvalues : " << nbvalues << std::endl;
    std::cout << "  - values" << std::endl;
    for (long int i = 0 ; i< nbmax ; i++){
        std::cout << "     - " << values[i] << std::endl;
    }
    std::cout << "-------------" << std::endl;
}

long int Tableau::length(){
    return nbvalues;
}

float Tableau::get(long int i){
    if (i >= nbvalues){
        return 0.0;
    }
    return values[i];
}

Tableau Tableau::operator+(Tableau tab){
    Tableau result;
    for (long int i = 0; i<nbmax;i++){
        result.push(get(i)+tab.get(i));
    }
    return result;
}


void Tableau::sort(bool asc){
    //Tri bulle
    float tmp;
    for (long int i = nbvalues - 1; i >0; i--){
        for (long int j = 0; j<i;j++){
            if ((asc && (values[j+1] < values[j])) || (!asc && (values[j+1] > values[j]))){
                tmp = values[j];
                values[j] = values[j+1];
                values[j+1] = tmp;
            }
        }
    }
}
