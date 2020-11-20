#include <stdlib.h>
#include <stdio.h>
#include "tab.h"

int main() {
	//On crée un tableau myTab1 avec 10 valeurs
	int myTab1[10];

	//On initialise le tableau myTab1 avec des 0
	initTab(myTab1, 10);

	//On crée un pointeur MyTab2 NULL
	int* MyTab2 = NULL;

	//On alloue la mémoire nécéssaire à la création du tableau
	MyTab2 = (int*)malloc(TAB2SIZE * sizeof(int));

	//On test si la mémoire est suffisante 
	if (MyTab2 != NULL) {
		initTab(MyTab2, TAB2SIZE);
	}
	else { 
		printf("mémoire insuffisante"); return(-1); 
	}

	//On initialise le tableau MyTab2 avec des 0
	initTab(MyTab2, TAB2SIZE);

	//On remplace les 20 premières valeurs par des valeurs allant de 1 à 20
	for (int i = 0; i < 20; i++) {
		*(MyTab2 + i) = i + 1;
	}

	//On affiche les 20 premières valeurs du tableau MyTab2
	afficheTab(MyTab2, TAB2SIZE, 20);

	//On crée des variables pour MyTab2
	int TABSIZE = 100;
	int NBELEMENT = 20;

	//On ajoute la valeur 21 à la suite de MyTab2
	ajoutElementDansTableau(MyTab2, &TABSIZE, &NBELEMENT, 21);

	//On affiche les 21 premières valeurs du tableau MyTab2
	afficheTab(MyTab2, TAB2SIZE, 21);

	//On détruit le tableau
	free(MyTab2);

	return EXIT_SUCCESS;
}