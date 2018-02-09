#include "bataille.h"

void creationDeck(CARTE * carte, int NbrCarte) {
	int i = 0;
	for (int valeur = 1; valeur <= NbrCarte / 4; valeur++)
	{
		for (int couleur = 1; couleur <= 4; couleur++)
		{
			(carte + i)->valeur = valeur;
			(carte + i)->couleur = couleur;
			i++;
		}

	}
}

void MelangeCarte(CARTE *carte, int Nbrcarte) {

	CARTE garder;
	int rand1;
	int rand2;
	for (int i = 0; i < 100; i++)
	{
		rand1 = rand() % Nbrcarte;
		rand2 = rand() % Nbrcarte;
		garder = *(carte + rand1);
		*(carte + rand1) = *(carte + rand2);
		*(carte + rand2) = garder;
	}

}
void Distribution(CARTE *carte, CARTE *j1, CARTE *j2, int Nbrcarte) {
	int i = 0;
	int Indicej1 = 0;
	int Indicej2 = 0;
	do
	{
		if (i % 2 == 0)
		{
			*(j1 + Indicej1) = *(carte + i);
			Indicej1++;
			//printf("J1 -- --  carte %d || couleur %d \n", (j1 + Indicej1)->valeur, (j1 + Indicej1)->couleur);
		}
		else
		{
			*(j2 + Indicej2) = *(carte + i);
			Indicej2++;
			//printf("J2 -- --  carte %d || couleur %d \n", (j2 + Indicej2)->valeur, (j2 + Indicej2)->couleur);
		}
		i++;
	} while (i < Nbrcarte);
}
void bataille(CARTE *j1, CARTE *j2, int Nbrcarte) {
	int i;
	int indiceMaxj1 = (Nbrcarte / 2) - 1;
	int indiceMaxj2 = (Nbrcarte / 2) - 1;
	int carteRanger;
	do
	{
		carteRanger = 0;
		if ((j1 + indiceMaxj1)->valeur < (j2 + indiceMaxj2)->valeur)
		{
			indiceMaxj2++;
			(j2 + indiceMaxj2)->valeur = (j1 + indiceMaxj1)->valeur;
			(j1 + indiceMaxj1)->valeur = 0;
			(j2 + indiceMaxj2)->couleur = (j1 + indiceMaxj1)->couleur;
			(j1 + indiceMaxj1)->couleur = 0;
			indiceMaxj1--;
			carteRanger = 2;
			decalerCarte(j2, indiceMaxj2, carteRanger);
		}
		else if ((j1 + indiceMaxj1)->valeur >(j2 + indiceMaxj2)->valeur)
		{
			indiceMaxj1++;
			(j1 + indiceMaxj2)->valeur = (j2 + indiceMaxj1)->valeur;
			(j2 + indiceMaxj2)->valeur = 0;
			(j1 + indiceMaxj2)->couleur = (j2 + indiceMaxj1)->couleur;
			(j2 + indiceMaxj2)->couleur = 0;
			indiceMaxj2--;
			carteRanger = 2;
			decalerCarte(j1, indiceMaxj1, carteRanger);
		}
		else
		{
			decalerCarte(j1, indiceMaxj1, carteRanger);
		}

	} while (j1->valeur < 0 && j1->valeur < 52);
}

void decalerCarte(CARTE *j, int indiceMaxj, int carteRanger) {
	int i = 0;
	int garderVal = 0;
	int garderCoul = 0;
	do
	{
		if ((j + i + 1)->valeur == 0)
		{
			j->valeur = (j + i)->valeur;
			j->couleur = (j + i)->couleur;
			i = 0;

		}
		else
		{
			(j + i + 1)->valeur = (j + i)->valeur;
			(j + i + 1)->couleur = (j + i)->couleur;
		}
		i++;
	} while (i < indiceMaxj);
}