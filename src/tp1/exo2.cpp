#include "exo2.h"

int factorielle(int n){
	if(n==0 || n==1){
		return 1;
	}
	int facto = 1;
	for(int i = 2; i<=n ; i++) {
		facto *= i;
	}
	return facto;
}

int factorielleComptageIteration(int n)
{
	static int nbIteration = 0;
	nbIteration++;
	if(n==0){
		std::cout << "Nombre d'itérations : " << nbIteration << std::endl;
		return 1;
	}
	return n*factorielleComptageIteration(n-1);
}

int coeffBinomial(int k, int n){ //k parmi n
	return (factorielle(n)/(factorielle(k)*factorielle(n-k)));
}

int timeInSecond(int h, int min, int s) {
	return (h*3600 + min*60 + s);
}

void afficherDureeSeconde(){
	int h1, m1, s1, h2, m2, s2;
	std::out << "Saisissez une heure en hh:mm:ss" << std::endl;
	std::cin >> h1 >> m1 >> s1 >> std::endl;
	std::out << "Saisissez une seconde heure en hh:mm:ss" << std::endl;
	std::cin >> h2 >> m2 >> s2 >> std::endl;

	std::out << "La durée entre les deux vaut : " << timeInSecond(h2,m2,s2) - timeInSecond(h1,m1,s1) << std::endl;
}
