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
void creationDeck(CARTE *, int );
void MelangeCarte(CARTE *, int );
void Distribution(CARTE *, CARTE *, CARTE *, int );
void AfficherCarte(CARTE * , int );
void AjoutCarteGagnant(CARTE* , CARTE * , int );
void SupprimerCarte(CARTE * , int , int );
void j1VSj2(CARTE * , CARTE * , int , CARTE *);

int CompterCarte(CARTE * , int );
int bataille(CARTE * , CARTE * , CARTE * , int );

#endif // BATAILLE
