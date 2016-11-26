#include <iostream>
#include "Color.h"
#include "Explorer.h"
#include <stdio.h>

int main()
{
    std::cout << "=== MyFileExplorer ===" << std::endl;
    Explorer* explorer = new Explorer("/");

    bool mustExit = false;
    std::string comand;
    while (!mustExit){
        std::cout << "$ ";
        std::cin >> comand;
        if (comand == "exit") {
            mustExit = true;
        } else if (comand == "pwd"){
            std::cout << Color::text(Color::BLUE,explorer->pwd()) << std::endl;
        } else if (comand == "ls"){
            explorer->ls();
        } else if (comand == "cd"){
            std::string comandArgs;
            std::cin >> comandArgs;
            try {
                explorer->cd(comandArgs);
            } catch (std::string e){
                std::cout << Color::text(Color::RED, e) << std::endl;
            }
        } else {
            std::cout << Color::text(Color::RED, "Commande inconnue !") << std::endl;
        }
    }
    delete explorer;
    return 0;
}
