#include "bataille.h"

int main() {
	srand(time(NULL));
	int nbCarte = 52;
	int compteurCarteMain1 = 0, compteurCarteMain2 = 0;

	Carte * deck = (Carte*)calloc(nbCarte, sizeof(Carte));
	Carte * Main1 = (Carte*)calloc(nbCarte, sizeof(Carte));
	Carte * Main2 = (Carte*)calloc(nbCarte, sizeof(Carte));
	if (deck != NULL && Main1 != NULL && Main2 != NULL)
	{
		CreateDeck(deck, nbCarte);

		MelangeDeck(deck, nbCarte);

		DistributionCarte(deck, Main1, Main2, nbCarte);
		
		do
		{

			Confrontation( Main1, Main2, nbCarte);
			printf("Le joueur 1 a %d cartes et le joeur 2 a %d cartes\n Pour un total de %d cartes", CompterCarte(Main1, nbCarte), CompterCarte(Main2, nbCarte), CompterCarte(Main1, nbCarte) + CompterCarte(Main2, nbCarte));
			
		} while (CompterCarte(Main1, nbCarte) != 0 && CompterCarte(Main2, nbCarte) != 0);

	}
	else {
		printf("Deso pas deso t'as pas assez Ram Ohh\n");
	}

	system("pause");
	return 0;
}