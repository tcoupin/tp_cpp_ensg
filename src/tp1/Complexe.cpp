#include "Complexe.h"
#include <iostream>
#include <math.h>

Complexe addition(Complexe& c1, Complexe& c2){
	Complexe c;
	c.re = c1.re + c2.re;
	c.re = c1.im + c2.im;
	return c;
}

float module(Complexe c){
    return sqrtf(powf(c.re,2.0)+powf(c.im,2.0)); //sqrt et pow avec un f puisqu'on travaille avec des float (cf http://en.cppreference.com/w/c/numeric/math/pow)
}

void afficherComplexe(Complexe c)
{
	std::cout << "(" << c.re << ", " << c.im << ")" << std::endl;
}
