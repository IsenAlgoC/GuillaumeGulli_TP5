#include "Header.h"

int main() {
	//On d�clare un tableau de structure tableau
	TABLEAU MonTableau;
	//On initialise le tableau avec la fonction newArray(), taille de d�part : 20, valeurs : 0 
	MonTableau = newArray();
	//On affiche les �lements de 0 � 20 du tableau
	displayElements(&MonTableau, 0, 20);
	//On met l'element 8 � la valeur 13
	setElement(&MonTableau, 8, 13);
	//On met l'element 21 � la valeur 9, on va augmenter la taille de 1 puisque la taille est de 20
	setElement(&MonTableau, 21, 9);
	//On affiche tous les �lements du tableau
	displayElements(&MonTableau, 0, MonTableau.size);
	//On met l'element 11 � la valeur 15
	setElement(&MonTableau, 11, 15);
	//On affiche tous les �lements du tableau
	displayElements(&MonTableau, 0, MonTableau.size);
	//On supprime les �lements de 2 � 6 inclus
	deleteElements(&MonTableau, 1, 5);
	//On affiche les �lements du tableau
	displayElements(&MonTableau, 0, MonTableau.size);

	return EXIT_SUCCESS;
}