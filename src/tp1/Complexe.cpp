#include "Complexe.h"
#include <iostream>

Complexe addition(Complexe& c1, Complexe& c2){
	Complexe c;
	c.re = c1.re + c2.re;
	c.re = c1.im + c2.im;
	return c;
}

double module(Complexe c){
	return ((c.re)**2+(c.im)**2)**(1/2);
}

void afficherComplexe(Complexe c)
{
	std::cout << "(" << c.re << ", " << c.im << ")" << std::endl;
}
