#pragma once
#include<stdio.h>
#include<stdlib.h>

#define TAILLEINITIALE 20

typedef struct Tableau {
	int* elt; // On definie le tableau d’entiers
	int size; // On definie la taille du tableau
	int eltsCount; // On definie le nombre d’éléments dans le tableau
} TABLEAU;


TABLEAU newArray();

int incrementArraySize(TABLEAU* tab, int incrementValue);
int setElement(TABLEAU* tab, int pos, int element);
int displayElements(TABLEAU* tab, int startPos, int endPos);
int deleteElements(TABLEAU* tab, int startPos, int endPos);