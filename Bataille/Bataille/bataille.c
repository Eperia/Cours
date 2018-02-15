#include "bataille.h"

void creationDeck(CARTE * carte, int NbrCarteTotal) {
	int i = 0;
	for (int valeur = 1; valeur <= NbrCarteTotal / 4; valeur++)
	{
		for (int couleur = 1; couleur <= 4; couleur++)
		{
			(carte + i)->valeur = valeur;
			(carte + i)->couleur = couleur;
			i++;
		}

	}
}

void MelangeCarte(CARTE *carte, int NbrCarteTotal) {

	CARTE garder;
	int rand1;
	int rand2;
	for (int i = 0; i < 100; i++)
	{
		rand1 = rand() % NbrCarteTotal;
		rand2 = rand() % NbrCarteTotal;
		garder = *(carte + rand1);
		*(carte + rand1) = *(carte + rand2);
		*(carte + rand2) = garder;
	}

}

void Distribution(CARTE *carte, CARTE *j1, CARTE *j2, int NbrCarteTotal) {
	int i = 0;
	int Indicej1 = 0;
	int Indicej2 = 0;
	do
	{
		if (i % 2 == 0)
		{
			*(j1 + Indicej1) = *(carte + i);
			Indicej1++;
			
		}
		else
		{
			*(j2 + Indicej2) = *(carte + i);
			Indicej2++;
			
		}
		i++;
	} while (i < NbrCarteTotal);
}

void AfficherCarte(CARTE * deck, int position) {

	switch ((deck + position)->valeur)
	{
	case 10:
		printf("Valet de ");
		break;
	case 11:
		printf("Dame de ");
		break;
	case 12:
		printf("Roi de ");
		break;
	case 13:
		printf("As de ");
		break;
	default:
		printf("%d de ", ((deck + position)->valeur) + 1);
		break;
	}

	switch ((deck + position)->couleur)
	{
	case 1:
		printf("Trefle");
		break;
	case 2:
		printf("Carreau");
		break;
	case 3:
		printf("Coeur");
		break;
	case 4:
		printf("Pique");
		break;
	default:
		break;
	}
	printf("\n");

}

void AjoutCarteGagnant(CARTE* Main, CARTE * zoneJeu, int nbCarteTotal) {
	int nbCarteMain;
	nbCarteMain = CompterCarte(Main, nbCarteTotal);
	for (int i = 0; i < CompterCarte(zoneJeu, nbCarteTotal); i++)
	{
		*(Main + nbCarteMain + i) = *(zoneJeu + i);
	}
}

void SupprimerCarte(CARTE * deck, int nbCarte, int nbrCarteSupr) {
	int nbrCarteMain;
	for (int i = 0; i < nbrCarteSupr; i++)
	{
		nbrCarteMain = CompterCarte(deck, nbCarte);
		for (int y = 0; y < nbrCarteMain - 1; y++)
		{
			*(deck + y) = *(deck + y + 1);
		}
		(deck + nbrCarteMain - 1)->valeur = 0;
		(deck + nbrCarteMain - 1)->couleur = 0;
	}
}

/*
Fonction qui gère la confrontation de base en 2 carte sinon fait appel a la fonction bataille
*/
void j1VSj2(CARTE * j1, CARTE * j2, int nbCarteTotal, CARTE *zoneJeu) {

	int nbCarteMain;
	int resultatBataille;
	system("cls");
	printf("J1 - ");
	AfficherCarte(j1, 0);
	printf("J2 - ");
	AfficherCarte(j2, 0);

	if (j1->valeur != j2->valeur)
	{
		// mets les cartes des 2 joueur sur la zone de jeu puis supprime les cartes
		*(zoneJeu) = *(j1);
		*(zoneJeu + 1) = *(j2);
		SupprimerCarte(j1, nbCarteTotal, 1);
		SupprimerCarte(j2, nbCarteTotal, 1);

		if (zoneJeu->valeur > (zoneJeu + 1)->valeur)
		{
			AjoutCarteGagnant(j1, zoneJeu, nbCarteTotal);
			printf("joueur 1 gagne la manche\n");
		}
		if (zoneJeu->valeur < (zoneJeu + 1)->valeur)
		{
			AjoutCarteGagnant(j2, zoneJeu, nbCarteTotal);
			printf("joueur 2 gagne la manche\n");
		}
	}
	else {

		resultatBataille = 0;
		do
		{
			printf("2 carte de valeur égal donc Bataille \n");
			resultatBataille = bataille(zoneJeu, j1, j2, nbCarteTotal);
			printf("\n");

			for (int i = 0; i < CompterCarte(zoneJeu, nbCarteTotal); i++)
			{
				AfficherCarte(zoneJeu, i);
			}

		} while (resultatBataille == 0);

		if (resultatBataille)
		{
			AjoutCarteGagnant(j1, zoneJeu, nbCarteTotal);
			printf("joueur 1 gagne la manche\n");
			printf("Ne t'inquiète pas joueur 1 souviens toi : \n tu a perdu une bataille !Mais tu n’a pas perdu la guerre !\n");
		}
		else {
			AjoutCarteGagnant(j2, zoneJeu, nbCarteTotal);
			printf("joueur 2 gagne la manche\n");
			printf("Ne t'inquiète pas joueur 2 souviens toi : \n tu a perdu une bataille !Mais tu n’a pas perdu la guerre !\n"); 
		}


		
	}
	system("pause");
}
	
int CompterCarte(CARTE * deck, int nbCarteTotal) {
	int nombreCarte = 0;

	while ((deck + nombreCarte)->valeur != 0 && nbCarteTotal != nombreCarte)
	{
		nombreCarte++;
	}

	return nombreCarte;
}

//algo non réussi
int bataille(CARTE * zoneJeu, CARTE * j1, CARTE * j2, int nbCarte) {
		return 0;
	}
