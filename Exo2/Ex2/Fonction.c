#include "Header.h"

TABLEAU newArray() {

	TABLEAU elt;
	elt.size = TAILLEINITIALE;                        // On initialise la taille initiale de elt.
	elt.elt = (int*)malloc(elt.size * sizeof(int));   // On alloue la mémoire nécessaire via un "malloc"!
	if (elt.elt == NULL) return elt;                  // On vérifie que la mémoire s'est bien allouée...
	for (int i = 0; i < elt.size; i++) {              // On initialise à 0 chaque valeur du tableau.
		*(elt.elt + i) = 0;
	}
	elt.eltsCount = 0;                // eltScount = 0 
	return elt;
}

int incrementArraySize(TABLEAU* tab, int incrementValue) {
	//On regarde si la reallocation est possible : 
	if ((int*)realloc(tab->elt, (tab->size + incrementValue) * sizeof(int)) == NULL) {
		return -1;
	}
	//On crée un pointeur temporaire tmp qui est une réallocation du pointeur elt dans tab
	else {

		int tmp = (int*)realloc(tab->elt, (tab->size + incrementValue) * sizeof(int));
		tab->elt = tmp;
		tab->size = tab->size + incrementValue;
		return tab->size;
	}
}

int setElement(TABLEAU* tab, int pos, int element) {
	//Si la position est negatif, on retourne 0 
	if (pos < 0) {
		return 0;
	}
	//Si on se positionne à l'intérieur du tableau alors on met à element la position pos-1 dans le tableau
	if (0 < pos && pos < tab->size) {
		tab->elt[pos - 1] = element;
	}
	//Sinon on a (pos > tab->size) donc il faut agrandir le tableau pour ajouter la valeur
	else {
		incrementArraySize(tab, pos - (tab->size));
		tab->elt[pos - 1] = element;
	}
	return pos;
}

int displayElements(TABLEAU* tab, int startPos, int endPos) {
	//Si on a une erreur, on retourne -1
	if (startPos > tab->size || endPos > tab->size || startPos < 0 || endPos < 0) {
		return -1;
	}
	//On affiche les valeurs de startPos à endPos
	else {
		for (int i = startPos; i < endPos; i++) {
			printf_s("%d ", *(tab->elt + i));
		}
		printf_s("\n");
	}
	return 0;
}

int deleteElements(TABLEAU* tab, int startPos, int endPos) {
	if (tab == NULL || startPos > endPos || startPos<0 || endPos>tab->size) {
		return -1;
	}

	else {
		//On va décaler les termes à partir de endPos jusque startPos
		for (int i = endPos; i < tab->size; i++) {
			tab->elt[startPos + (i - endPos) - 1] = tab->elt[i];
		}
		//On supprime les élements qui ont été déplacés
		for (int i = tab->size - endPos + 1; i < tab->size; i++) {
			tab->elt[i] = NULL;
		}
		//On alloue une nouvelle taille plus petite
		int tmp = (int*)realloc(tab->elt, (tab->size - (endPos - startPos)) * sizeof(int));
		tab->elt = tmp;
		//On réduit size du tableau
		tab->size = tab->size - (endPos - startPos + 1);
	}
	return tab->size;
}