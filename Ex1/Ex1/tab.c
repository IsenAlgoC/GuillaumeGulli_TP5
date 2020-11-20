#include <stdlib.h>
#include<stdio.h>
#include "tab.h"

int initTab(int* tab, int size) {
	//On test si le tableau n'est pas NULL
	if (size < 0 || tab == NULL) {
		return -1;
	}
	else {
		//On parcourt le tableau à l'aide de la boucle for : 
		for (int i = 0; i < size; i++) {
			//On remplace chaque terme du tableau par 0 :
			*(tab + i) = 0;
		}
		return size;
	}
}

int afficheTab(int* tab, int size, int nbElts) {
	//Si le tableau est NULL ou si size<0 ou si size<nbElts, on renvoie -1
	if (size <= 0 || tab == NULL || nbElts > size) {
		return -1;
	}
	else {
		//On affiche les nbElts premiers elements du tableau
		for (int i = 0; i < nbElts; i++) {
			printf("%d  ", *(tab + i));
		}
		printf_s("\n");
		return 0;
	}
}

int ajoutElementDansTableau(int* tab, int* size, int* nbElts, int element) {
	// Fonction qui  ajoute un nombre entier à la suite des valeurs déjà entrées et met 
	// à jour le nombre d'éléments stockés ainsi que la capacité réelle du tableau
	if (*size <= 0 || tab == NULL) {
		return -1;
	}
	if (*nbElts >= *size) {
		//On crée un pointeur temporaire (réallocation du pointeur tab sur la taille nécéssaire) pour ajouter une valeur
		int* tmp = (int*)realloc(tab, (TAILLEAJOUT + *size) * sizeof(int));
		//Si l'agrandissement échoue, on renvoie -1
		if (tmp == NULL) {				
			return -1;
		}
		else {
			tab = tmp;
			// On initialise les dernières valeurs du nouveau tableau à 0
			for (int i = 0; i < TAILLEAJOUT; i++) {
				*(tab + i + *size) = 0;
			}
			*size += TAILLEAJOUT;
		}
	}
	//Sinon cela signifie que la taille est suffisante pour acceuilir un nouvel élément, on ajoute simplement le nouvel élément dans le tableau
	else {
		*nbElts = *nbElts + 1;
		*(tab + *nbElts - 1) = element;
	}
	//Si les opérations ont réussi, on renvoie le nombre d'éléments dans le tableau
	return *nbElts;
}