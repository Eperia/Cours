#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include "bataille.h"

int main() {
	srand(time(NULL));
	int NbrCarte = 52;
	int i;
	CARTE *carte = (CARTE *)calloc(NbrCarte, sizeof(CARTE));
	CARTE *j1 = (CARTE *)calloc(NbrCarte, sizeof(CARTE));
	CARTE *j2 = (CARTE *)calloc(NbrCarte, sizeof(CARTE));
	if (carte !=NULL)
	{

		creationDeck(carte, NbrCarte);
		for (i = 0;i < NbrCarte; i++)
		{
			printf("carte %d || couleur %d \n", (carte + i)->valeur, (carte + i)->couleur);
		}
		system("pause");
		system("cls");

		MelangeCarte(carte, NbrCarte);
		for (i = 0; i < NbrCarte; i++)
		{
			printf("carte %d || couleur %d \n", (carte + i)->valeur, (carte + i)->couleur);
		}

		system("pause");
		system("cls");

		Distribution(carte, j1, j2, NbrCarte);
		for (i = 0; i < NbrCarte/2; i++)
		{
			printf("J1 -- --  carte %d || couleur %d \n", (j1 + i)->valeur, (j1 + i)->couleur);
		}

		system("pause");
		system("cls");

		for (i = 0; i < NbrCarte/2; i++)
		{
			printf("J2 -- --  carte %d || couleur %d \n", (j2 + i)->valeur, (j2 + i)->couleur);
		}
		system("pause");
		system("cls");

		bataille(j1, j2, NbrCarte);

		for (i = 0; (j1 + i)->valeur != 0 / 2; i++)
		{
			printf("J1 -- --  carte %d || couleur %d \n", (j1 + i)->valeur, (j1 + i)->couleur);
		}

		system("pause");
		system("cls");

		for (i = 0; (j2 + i)->valeur!=0 / 2; i++)
		{
			printf("J2 -- --  carte %d || couleur %d \n", (j2 + i)->valeur, (j2 + i)->couleur);
		}
		system("pause");
	}
	else
	{
		printf("Probleme d'allocation dynamique (l.11)\n'CARTE *carte = (CARTE *)calloc(NbrCarte, sizeof(CARTE));'\n");
	}

	return 0;
}