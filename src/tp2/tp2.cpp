#include <iostream>
#include "Tableau.h"
#include "TableauDyn.h"

void tp2_exo1_part1(){
    std::cout << "--- TP2/Tableau/Test surallocation ---" << std::endl;

    Tableau mTable;

    mTable.push(1.1);
    mTable.push(1.2);
    mTable.push(1.3);
    mTable.push(1.4);
    mTable.print();

    mTable.push(1.5);
    mTable.push(1.6);
    mTable.push(1.7); // ça devrait commencer à coincer ici

    mTable.print();

    char surAllocate = 'n';
    std::cout << "On tente une surallocation ? [y/N]";
    std::cin >> surAllocate;
    if (surAllocate == 'y' || surAllocate == 'Y'){
        mTable.pushUnsecure(1.7); // avec ça, ça va tout péter;
        mTable.print();
    }
}

void tp2_exo1_part2(){

    std::cout << "--- TP2/Tableau/Test méthodes ---" << std::endl;

    Tableau monTableau;
    monTableau.input();
    monTableau.print();
    std::cout << "Sum  : " << monTableau.sum() << std::endl;
    std::cout << "Mean : " << monTableau.mean() << std::endl;

    Tableau deuziemeT;
    deuziemeT.push(10);
    deuziemeT.push(11);
    deuziemeT.push(12);
    deuziemeT.print();

    Tableau troiz = monTableau + deuziemeT;
    troiz.print();
    troiz.sort();
    troiz.print();
    troiz.sort(false);
    troiz.print();
}

void afficheTableau(TableauDyn tab){
    std::cout << "---afficheTableau ";
    tab.print();
    std::cout << "---FIN afficheTableau " << std::endl ;
}

void tp2_exo2(){

    std::cout << "--- TP2/TableauDyn/Test méthodes ---" << std::endl;
    TableauDyn mTableDyn(3);
    mTableDyn.input();
    mTableDyn.print();

    mTableDyn = TableauDyn(2); // Possible grâce à la surcharge de l'opérateur =. Une bonne explication sur http://stackoverflow.com/a/6575474
    mTableDyn.input();
    mTableDyn.print();

    std::cout << "--- TP2/TableauDyn/Affichage ---" << std::endl;
    afficheTableau(mTableDyn);
    mTableDyn.print();
}



void tp2(){
    std::cout << "=== TP2 ===" << std::endl;
    //tp2_exo1_part1();
    //tp2_exo1_part2();
    tp2_exo2();
}

