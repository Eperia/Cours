#include "Bataille.h"

void CreateDeck(Carte* deck, int nbCarte) {
	int i = 0;
	for (int valeur = 1; valeur <= nbCarte/4; valeur++)
	{
		for (int couleur = 1; couleur <= 4 ; couleur++)
		{
			(deck+i)->valeur = valeur;
			(deck+i)->couleur = couleur;
			i++;
		}
	}
}

void MelangeDeck(Carte* deck, int nbCarte) {

	Carte intermediaire;

	int rand1, rand2;

	for (int i = 0; i < 10000; i++)
	{
		rand1 = rand() % nbCarte;
		rand2 = rand() % nbCarte;
		intermediaire = *(deck + rand1);
		*(deck + rand1) = *(deck + rand2);
		*(deck + rand2) = intermediaire;
	}

}

void AfficherCarte(Carte * deck, int position) {

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
		printf("%d de ", ((deck + position)->valeur)+1);
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

void DistributionCarte(Carte * deck, Carte * Main1, Carte * Main2, int nbCarte) {
	
	int x = 0, y = 0;
	for (int i = 0; i < nbCarte; i++)
	{
		if (i%2 == 0)
		{
			*(Main1 + x) = *(deck + i);
			x++;
		}
		else
		{
			*(Main2 + y) = *(deck + i);
			y++;
		}
	}

}

int CompterCarte(Carte * deck, int nbCarte) {
	int nombreCarte = 0;

	while ((deck + nombreCarte)->valeur != 0 && nbCarte != nombreCarte)
	{
		nombreCarte++;
	}

	return nombreCarte;
}

void SupprimerCarte(Carte * deck, int nbCarte, int nbCarteSupr) {
	int nbCarteMain;
	for (int i = 0; i < nbCarteSupr; i++)
	{
		nbCarteMain = CompterCarte(deck, nbCarte);
		for (int y = 0; y < nbCarteMain - 1; y++)
		{
			*(deck + y) = *(deck + y + 1);
		}
		(deck + nbCarteMain - 1)->valeur = 0;
		(deck + nbCarteMain - 1)->couleur = 0;
	}
}

void AjoutCarteGagnant(Carte* Main, Carte * Pile, int nbCarte) {
	int nbCarteMain;
	nbCarteMain = CompterCarte(Main, nbCarte);
	for (int i = 0; i < CompterCarte(Pile, nbCarte); i++)
	{
		*(Main + nbCarteMain + i) = *(Pile + i);
	}
}

int bataille(Carte * Pile, Carte * Main1, Carte * Main2, int nbCarte) {
	int varBataille;
	int nbCartePile = CompterCarte(Pile, nbCarte);
	int x = 0, y = 0;
	for (int i = nbCartePile; i < nbCartePile + 6; i++)
	{
		if (i%2 == 0)
		{
			*(Pile+i) = *(Main1+x);
			x++;
		}
		else {
			*(Pile+i) = *(Main2+y);
			y++;
		}
	}
	SupprimerCarte(Main1, nbCarte, 3);
	SupprimerCarte(Main2, nbCarte, 3);
	nbCartePile = CompterCarte(Pile, nbCarte);
	printf("On confronte donc %d et %d\n", (Pile+nbCartePile-2)->valeur, (Pile + nbCartePile-1)->valeur);
	if ((Pile + nbCartePile - 2)->valeur > (Pile + nbCartePile - 1)->valeur)
	{
		varBataille = 1;
	}
	else if ((Pile + nbCartePile - 2)->valeur < (Pile + nbCartePile - 1)->valeur)
	{
		varBataille = 2;
	}
	else {
		varBataille = 0;
	}
	return varBataille ;
}

void Confrontation(Carte * Main1, Carte * Main2, int nbCarte) {
	Carte * Pile = (Carte*)calloc(52, sizeof(Carte));
	int nbCarteMain;
	int varBataille;
	printf("On confronte %d et %d\n", Main1->valeur, Main2->valeur);
	if (Main1->valeur != Main2->valeur)
	{
		*(Pile) = *(Main1);
		*(Pile+1) = *(Main2);
		SupprimerCarte(Main1, nbCarte, 1);
		SupprimerCarte(Main2, nbCarte, 1);
		if (Pile->valeur > (Pile+1)->valeur)
		{
			AjoutCarteGagnant(Main1, Pile, nbCarte);
			printf("Victoire du joueur 1\n");
		}
		if (Pile->valeur < (Pile + 1)->valeur)
		{
			AjoutCarteGagnant(Main2, Pile, nbCarte);
			printf("Victoire du joueur 2\n");
		}
	}
	else {

		varBataille = 0;
		do
		{
			printf("Bataille !!\n");
			varBataille = bataille(Pile, Main1, Main2, nbCarte);
			printf("\n\n");
			for (int i = 0; i < CompterCarte(Pile, nbCarte); i++)
			{
				AfficherCarte(Pile, i);
			}
		} while (varBataille == 0 );
		if (varBataille == 1)
		{
			AjoutCarteGagnant(Main1, Pile, nbCarte);
			printf("Victoire du joueur 1\n");
		}
		else {
			AjoutCarteGagnant(Main2, Pile, nbCarte);
			printf("Victoire du joueur 2\n");
		}

	}
	printf("Main 1\n");
	for (int i = 0; i < CompterCarte(Main1, nbCarte); i++)
	{
		AfficherCarte(Main1, i);
	}
	printf("\n\n");
	printf("Main 2\n");
	for (int i = 0; i < CompterCarte(Main2, nbCarte); i++)
	{
		AfficherCarte(Main2, i);
	}
	free(Pile);

}