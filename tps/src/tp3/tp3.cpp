#include "tp3.h"
#include "tElt.h"
#include "tabDyn2D.h"

void tp3(){
    std::cout << "=== TP3 ===" << std::endl;
    std::cout << "--- TP3/template ---" << std::endl;
    tElt<float> tab(1);
    tab.print();

    std::cout << "--- TP2/tabDyn2D ---" << std::endl;
    tabDyn2D t(5,3);
    t.affiche();
}
