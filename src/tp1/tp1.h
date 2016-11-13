#include <iostream>
#include "exo1.h"
#include "exo2.h"

void tp1_exo1(){
    std::cout << "--- TP1/Exo1 ---" << std::endl;
    std::cout << "--- TP1/Exo1/Afficher les entiers ---" << std::endl;
    afficherEntier(30);
    std::cout << "--- TP1/Exo1/Afficher les carrés ---" << std::endl;
    afficherCarresEntiers(45);
    std::cout << "--- TP1/Exo1/Afficher les entiers multiples de 5 ---" << std::endl;
    afficherNombre(100,5);

}

void tp1_exo2(){
    std::cout << "--- TP1/Exo2 ---" << std::endl;
    std::cout << "--- TP1/Exo2/Afficher une factorielle ---" << std::endl;
    std::cout << "!10=" << factorielle(10) <<std::endl;

    std::cout << "--- TP1/Exo2/Afficher une factorielle avec compteur ---" << std::endl;
    factorielleComptageIteration(15);

    std::cout << "--- TP1/Exo2/Afficher un coeeficient binomial ---" << std::endl;
    coeffBinomial(2,6);

    std::cout << "--- TP1/Exo2/Afficher une durée ---" << std::endl;
    afficherDureeSeconde();

}

void tp1(){
    std::cout << "=== TP1 ===" << std::endl;
    tp1_exo1();
    tp1_exo2();
}
