#include <iostream>
#include "exo1.h"

void afficherEntier(int max,int min)
{
	for ( int i = min ; i <= max ; i++ ) {
		std::cout << i << std::endl ;
	}
}

void afficherCarresEntiers(int max, int min){
	int i = min ;
	while ( i <= max ) {
		std::cout << i*i << std::endl ;
	}
}

void afficherNombre(int max, int multiple,int min){
	for ( int i = min ; i <= max ; i++ ) {
		if (i%multiple != 0) {
			continue ;
		}
		std::cout << i << std::endl ;
	}
}
