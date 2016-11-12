#include "tTableau.h"
#include <iostream>

tTableau::tTableau() : nbvalues(0)
{
    std::cout << "tTableau : création" << std::endl;
}

tTableau::~tTableau()
{
    std::cout << "tTableau : extermination" << std::endl;
}

void tTableau::push(float value) {
    if (nbvalues == nbmax){
        std::cout << "tTableau : je suis rempli" << std::endl;
        return;
    }
    values[nbvalues++] = value; // On met le ++ après la valeur pour que l'indice soit la valeur actuelle puis on l'incrémente
    // values[++nbvalues] = value; // on commencerai à remplire à la case 1 alors que ça commence à 0
}

float tTableau::sum() {
    float sum;
    for (long int i = 0;i<nbvalues;i++){
        sum += values[i];
    }
    return sum;
}

float tTableau::mean(){
    if (nbvalues == 0){
        return 0.0;
    }
    return sum()/nbvalues;
}

void tTableau::input(){
    std::cout << "tTableau : à toi de bosser" << std::endl;
    for (long int i = 0;i<nbmax;i++){
        std::cin >> values[i];
        nbvalues++;
    }
}

void tTableau::pushUnsecure(float value) {
    values[nbvalues++] = value;
}

void tTableau::print(){
    std::cout << "---tTableau--" << std::endl;
    std::cout << "  - nbmax    : " << nbmax << std::endl;
    std::cout << "  - nbvalues : " << nbvalues << std::endl;
    std::cout << "  - values" << std::endl;
    for (long int i = 0 ; i< nbvalues ; i++){
        std::cout << "     - " << values[i] << std::endl;
    }
    std::cout << "-------------" << std::endl;
}
void tTableau::printAll(){
    std::cout << "---tTableau--" << std::endl;
    std::cout << "  - nbmax    : " << nbmax << std::endl;
    std::cout << "  - nbvalues : " << nbvalues << std::endl;
    std::cout << "  - values" << std::endl;
    for (long int i = 0 ; i< nbmax ; i++){
        std::cout << "     - " << values[i] << std::endl;
    }
    std::cout << "-------------" << std::endl;
}

long int tTableau::length(){
    return nbvalues;
}

float tTableau::get(long int i){
    if (i >= nbvalues){
        return 0.0;
    }
    return values[i];
}

tTableau tTableau::operator+(tTableau tab){
    tTableau result;
    for (long int i = 0; i<nbmax;i++){
        result.push(get(i)+tab.get(i));
    }
    return result;
}


void tTableau::sort(){
    //Tri bulle
    float tmp;
    for (long int i = nbvalues - 1; i >0; i--){
        for (long int j = 0; j<i;j++){
            if (values[j+1] < values[j]){
                tmp = values[j];
                values[j] = values[j+1];
                values[j+1] = tmp;
            }
        }
    }
}
