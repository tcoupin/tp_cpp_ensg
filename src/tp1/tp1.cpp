#include <iostream>
#include "exo1.h"
#include "exo2.h"
#include "Complexe.h"
#include "pointeurs.h"


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

void tp1_ecoComplexe(){
    std::cout << "--- TP1/ExoComplexe ---" << std::endl;
    std::cout << "--- TP1/ExoComplexe/Création d'un complexe ---" << std::endl;
    float re, im;
    std::cin >> re;
    std::cin >> im;
    Complexe c = {re, im};
    std::cout << "--- TP1/ExoComplexe/Création d'un autre complexe ---" << std::endl;
    float re1, im1;
    std::cin >> re1 >> im1;
    Complexe c1 = {re1, im1};
    std::cout << "--- TP1/ExoComplexe/Affichage de l'addition des deux ---" << std::endl;
    afficherComplexe(addition(c,c1));
    std::cout << "--- TP1/ExoComplexe/Affichage du module du deuxième ---" << std::endl;
    std::cout << module(c1) << std::endl;
}

void tp1_pointeurs(){
    std::cout << "--- TP1/ExoPointeur ---" << std::endl;
    std::cout << "--- TP1/ExoPointeur/Swap ---" << std::endl;
    int* pa=2;
    int* pa=3;
    std::cout << "pa : " << pa << " | pb : " << pb << std::endl;
    swap(pa,pb);
    std::cout << "pa : " << pa << " | pb : " << pb << std::endl;
    std::cout << "--- TP1/ExoPointeur/Min et Max d'un tableau ---" << std::endl;
}

void tp1(){
    std::cout << "=== TP1 ===" << std::endl;
    tp1_exo1();
    tp1_exo2();
    tp1_ecoComplexe();
}
