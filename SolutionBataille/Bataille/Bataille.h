#pragma once
#ifndef BATAILLE
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

typedef struct
{

	int valeur;
	int couleur;

} Carte;


void CreateDeck(Carte*, int);
void MelangeDeck(Carte*, int);
void AfficherCarte(Carte *, int);
void DistributionCarte(Carte *, Carte * , Carte * , int);
int CompterCarte(Carte *, int);
void AjoutCarteGagnant(Carte*, Carte*, int);
void Confrontation(Carte*, Carte*, int);
void SupprimerCarte(Carte *, int, int);
int bataille(Carte *,Carte * , Carte *,int);
#define BATAILLE
#endif // !BATAILLE

