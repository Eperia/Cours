#ifndef BATAILLE
#define BATAILLE

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct
{
	int valeur;
	int couleur;
	// 1-trèfle, 2-carreau, 3-coeur, 4-pique
}CARTE;
void creationDeck(CARTE *carte, int NbrCarte);
void MelangeCarte(CARTE *carte, int Nbrcarte);
void Distribution(CARTE *carte, CARTE *j1, CARTE *j2, int Nbrcarte);
void decalerCarte(CARTE *j, int indiceMaxj, int carteRanger);
#endif // BATAILLE
