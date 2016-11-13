#include <iostream>
#include "exos1.h"

void afficherEntier(int min = 0, int max)
{
	for ( int i = min ; i <= max ; i++ ) {
		std::cout << i << std::endl ;
	}
}

void afficherCarresEntiers(int min = 0, int max){
	int i = min ;
	while ( i <= max ) {
		std::cout << i*i << std::endl ;
	}
}

void afficherNombre(int min = 0, int max, int multiple){
	for ( int i = min ; i <= max ; i++ ) {
		if (i%multiple != 0) {
			continue ;
		}
		std::cout << i << std::endl ;
	}
}
