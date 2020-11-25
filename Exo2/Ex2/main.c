#include "Header.h"

int main() {
	//On déclare un tableau de structure tableau
	TABLEAU MonTableau;
	//On initialise le tableau avec la fonction newArray(), taille de départ : 20, valeurs : 0 
	MonTableau = newArray();
	//On affiche les élements de 0 à 20 du tableau
	displayElements(&MonTableau, 0, 20);
	//On met l'element 8 à la valeur 13
	setElement(&MonTableau, 8, 13);
	//On met l'element 21 à la valeur 9, on va augmenter la taille de 1 puisque la taille est de 20
	setElement(&MonTableau, 21, 9);
	//On affiche tous les élements du tableau
	displayElements(&MonTableau, 0, MonTableau.size);
	//On met l'element 11 à la valeur 15
	setElement(&MonTableau, 11, 15);
	//On affiche tous les élements du tableau
	displayElements(&MonTableau, 0, MonTableau.size);
	//On supprime les élements de 2 à 6 inclus
	deleteElements(&MonTableau, 1, 5);
	//On affiche les élements du tableau
	displayElements(&MonTableau, 0, MonTableau.size);

	return EXIT_SUCCESS;
}