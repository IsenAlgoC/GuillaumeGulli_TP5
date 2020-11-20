#pragma once

//Déclaration des constantes
#define TAB2SIZE 100
#define TAILLEAJOUT 50

//Déclaration des fonctions
int initTab(int* tab, int size);
int afficheTab(int* tab, int size, int nbElts);
int ajoutElementDansTableau(int* tab, int* size, int* nbElts, int element);

