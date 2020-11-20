#include <stdlib.h>
#include<stdio.h>
#include "tab.h"

int initTab(int* tab, int size) {
	//On test si le tableau n'est pas NULL
	if (size < 0 || tab == NULL) {
		return -1;
	}
	else {
		//On parcourt le tableau � l'aide de la boucle for : 
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
	// Fonction qui  ajoute un nombre entier � la suite des valeurs d�j� entr�es et met 
	// � jour le nombre d'�l�ments stock�s ainsi que la capacit� r�elle du tableau
	if (*size <= 0 || tab == NULL) {
		return -1;
	}
	if (*nbElts >= *size) {
		//On cr�e un pointeur temporaire (r�allocation du pointeur tab sur la taille n�c�ssaire) pour ajouter une valeur
		int* tmp = (int*)realloc(tab, (TAILLEAJOUT + *size) * sizeof(int));
		//Si l'agrandissement �choue, on renvoie -1
		if (tmp == NULL) {				
			return -1;
		}
		else {
			tab = tmp;
			// On initialise les derni�res valeurs du nouveau tableau � 0
			for (int i = 0; i < TAILLEAJOUT; i++) {
				*(tab + i + *size) = 0;
			}
			*size += TAILLEAJOUT;
		}
	}
	//Sinon cela signifie que la taille est suffisante pour acceuilir un nouvel �l�ment, on ajoute simplement le nouvel �l�ment dans le tableau
	else {
		*nbElts = *nbElts + 1;
		*(tab + *nbElts - 1) = element;
	}
	//Si les op�rations ont r�ussi, on renvoie le nombre d'�l�ments dans le tableau
	return *nbElts;
}