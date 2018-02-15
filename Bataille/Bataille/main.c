#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include "bataille.h"

int main() {
	srand(time(NULL));
	int NbrCarte = 52;
	int i;
	/*
	zoneJeu signifie la ou on pose nos carte
	carte signifie les carte en général
	j1 signifie le main du joueur 1
	j2 signifie la main du joueur 2
	*/
	CARTE * zoneJeu = (CARTE*)calloc(52, sizeof(CARTE));
	CARTE *carte = (CARTE *)calloc(NbrCarte, sizeof(CARTE));
	CARTE *j1 = (CARTE *)calloc(NbrCarte, sizeof(CARTE));
	CARTE *j2 = (CARTE *)calloc(NbrCarte, sizeof(CARTE));
	if (carte !=NULL)
	{

		creationDeck(carte, NbrCarte);
		for (i = 0;i < NbrCarte; i++)
		{
			AfficherCarte(carte, i);;
		}
		system("pause");
		system("cls");

		MelangeCarte(carte, NbrCarte);

		for (i = 0; i < NbrCarte; i++)
		{
			AfficherCarte(carte, i);;
		}
		system("pause");
		system("cls");
		Distribution(carte, j1, j2, NbrCarte);

		printf("--------------- Deck du joueur 1 ---------------\n");
		for (i = 0; i < NbrCarte/2; i++)
		{
			AfficherCarte(j1, i);
		}
		system("pause");
		system("cls");

		printf("--------------- Deck du joueur 2 ---------------\n");
		for (i = 0; i < NbrCarte/2; i++)
		{
			AfficherCarte(j2, i);
		}
		system("pause");
		system("cls");		

		do
		{
			j1VSj2(j1, j2, NbrCarte, zoneJeu);
		} while (CompterCarte(j1, NbrCarte) != 0 && CompterCarte(j2, NbrCarte) != 0);

		if (!(CompterCarte(j1, NbrCarte)))
		{
			printf("Félicitation J2 pour avoir gagner a la bataille");
		}
		else
		{
			printf("Félicitation J1 pour avoir gagner a la bataille");
		}

		system("pause");

		free (zoneJeu);
		free (carte);
		free (j1);
		free (j2);
	}
	else
	{
		printf("Probleme d'allocation dynamique \n");
	}

	return 0;
}