


#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {


	//Une fonction qui initialise un tableau avec des valeurs aléatoires
	srand(time(NULL));
	int tab1[5];
	int tab2[5];
	int tabx[3] = { 1,2,3 };
	int taby[5] = { 4,5,6,7,8 };
	int tabz[8] = { 0 };
	int taillex = 3;
	int tailley = 5;
	int taillez = 8;
	int a;
	int b;
	int taille = 5;
	int somme;
	int compteur;
	int minimum;
	int position;
	int garder;
	int choix;
	int test;
	int choix1;
	int choix2;
	int i = 0;
	int moyenne;
	int valeurRecherchee = 0;
	int valeurProposee = 0;
	int max = taille;


	while (i < taille) {
		//traitement
		tab1[i] = rand() % 11;
		i++;
	}

	//i = 0;
	//while (i < taille) {
	//	printf("%d | ", tab1[i]);
	//	i++;
	//}
	//printf("\n");
	//i = 0;
	//while (i < taille) {
	//	tab2[i] = 5;
	//	i++;
	//}
	//i = 0;
	//while (i < taille) {
	//	printf("%d | ", tab2[i]);
	//	i++;
	//}
	//printf("\n");

	////La somme du tableau 1
	//i = 0;
	//somme = 0;
	//while (i < taille) {
	//	somme = somme + tab1[i];
	//	i++;
	//}
	//printf("La somme vaut : %d\n", somme);

	////Une fonction qui renvoie le nombre d'éléments pair d'un tableau
	//compteur = 0;
	//i = 0;

	//while (i < taille) {
	//	if (tab1[i] % 2 == 0)
	//	{
	//		compteur++;
	//	}
	//	i++;
	//}
	//printf("Il y a %d elements pairs\n", compteur);


	////Une fonction qui renvoie la plus petite valeur d'un tableau
	//minimum = tab1[0];
	//i = 0;
	//while (i < taille) {
	//	if (tab1[i] < minimum) {
	//		minimum = tab1[i];
	//	}
	//	i++;
	//}
	//printf("La plus petite valeur est %d\n", minimum);
	//system("pause");


	////Une fonction qui renvoie la plus petite valeur d'un tableau et son indice
	//minimum = tab1[0];
	//i = 0;
	//while (i < taille) {
	//	if (tab1[i] < minimum) {
	//		minimum = tab1[i];
	//		position = i + 1;
	//	}
	//	i++;
	//}
	//printf("La plus petite valeur est %d et est a la position %d \n", minimum, position);
	//system("pause");



	////Une fonction qui l'ordre

	//i = 0;
	//while (i < taille / 2) {
	//	garder = tab1[i];
	//	tab1[i] = tab1[taille - 1 - i];
	//	tab1[taille - 1 - i] = garder;
	//	i++;
	//}

	//i = 0;
	//while (i < taille) {
	//	printf("%d | ", tab1[i]);
	//	i++;
	//}






	//test = -1;
	//i = 0;
	//position = 1;
	//// Rechercher une valeur dans un tableau. Retourner la position de la première occurrence de la valeur dans le tableau. Si la valeur n’existe pas, retourner -1
	//printf("choisir quelle valeur chercher\n");
	//scanf("%d", &choix);
	//while (i - 1 < taille && tab1[position - 1] != choix) {

	//	if (tab1[i] == choix) {

	//		position = i + 1;
	//		test = 0;
	//	}
	//	else
	//	{
	//		position = -1;
	//	}


	//	i++;
	//}
	//printf("le nbr %d est a la position %d \n", choix, position);

	//// Rechercher une valeur dans un tableau. Retourner la position de la dernière occurrence de la valeur dans le tableau. Si la valeur n’existe pas, retourner -1
	//i = 0;
	//position = -1;
	//printf("choisir quelle valeur chercher\n");
	//scanf("%d", &choix);
	//while (i - 1 < taille) {

	//	if (tab1[i] == choix) {

	//		position = i + 1;

	//	}


	//	i++;
	//}
	//printf("le nbr %d est a la position %d \n", choix, position);

	//system("pause");

	////Demander a l’utilisateur de saisir un entier. Compter le nombre de fois que cette valeur est présente dans le tableau. 

	//test = -1;
	//i = 0;
	//position = 0;
	//printf("choisir quelle valeur chercher\n");
	//scanf("%d", &choix);
	//while (i < taille) {

	//	if (tab1[i] == choix) {

	//		position++;

	//	}



	//	i++;
	//}
	//printf("le nbr %d est present %d \n", choix, position);


	////Fusionner 2 tableaux dans un troisième ayant suffisamment de cases – les valeurs d’un tableau de 3 cases et d’un tableau de 5 cases se retrouvent dans un tableau de 8 cases 

	//i = 0;
	//a = 0;
	//b = 0;


	//while (i < taillez) {
	//	if (a < taillex)
	//	{
	//		tabz[i] = tabx[a];
	//		a++;

	//	}
	//	else if (b < tailley) {
	//		tabz[i] = taby[b];
	//		b++;
	//	}
	//	i++;
	//}

	//i = 0;
	//while (i < taillez) {
	//	printf("%d | ", tabz[i]);
	//	i++;
	//}
	//choix1 = 0;
	//choix2 = 0;
	//Demander l’utilisateur 2 positions de cases. Echanger les valeurs de ces deux positions
	//i = 0;
	//while (i < taille) {
	//	printf("%d | ", tab1[i]);
	//	i++;
	//}
	//	printf("choisir 1 position");
	//	scanf("%d",&choix1);
	//	printf("choisir une deuxieme position");
	//	scanf("%d",&choix2);
	//
	//	garder = tab1[choix1 - 1];
	//	tab1[choix1-1] = tab1[choix2-1];
	//	tab1[choix2-1] = garder;
	//	
	//	i = 0;
	//	while (i < taille) {
	//		printf("%d | ", tab1[i]);
	//		i++;
	//	}
	//
	////moyenne tableau
	//	i = 0;
	//	moyenne = 0;
	//	while (i < taille) {
	//		moyenne += tab1[i];
	//		i++;
	//	}
	//	moyenne = moyenne / taille;
	//	printf("le moyenne est %d", moyenne);
	//	system("pause");
	//  Demander  l’utilisateur une valeur. Faire en sorte que cette valeur soit la première valeur du tableau et décaler la première case du tableau dans la deuxième etc… La dernière valeur du tableau est perdue
	//i = 0;
	//while (i < taille) {
	//	printf("%d | ", tab1[i]);
	//	i++;
	//}
	//printf("choisir une valeur");
	//scanf("%d", &choix);
	//i = taille - 1;

	//while (i > 0) {
	//	tab1[i] = tab1[i - 1];
	//	i--;
	//}
	//tab1[0] = choix;
	i = 0;
	while (i < taille) {
		printf("%d | ", tab1[i]);
		i++;
	}
	printf("\n");
	i = 0;
	a = 0;
	int min;
	int indice;
	int garde = 0;
	while (i < taille) {

		min = tab1[i];
		indice = a;
		while (a < taille)
		{
			if (min > tab1[a])
			{
				min = tab1[a];
				indice = a;
			}
			a++;
		}
		garde = tab1[i];
		tab1[i] = tab1[indice];
		tab1[indice] = garde;
		i++;
		a = i;

	}
	i = 0;
	while (i < taille) {
		printf("%d | ", tab1[i]);
		i++;
	}

	min = 0;
	i = 0;
	printf("\n Saisir la veleur rechercher\n");
	scanf(" %d", &valeurRecherchee);


	do {
		indice = (min + max) / 2;
		valeurProposee = tab1[indice];
		if (valeurProposee < valeurRecherchee) {
			min = indice;
		}
		else if (valeurProposee > valeurRecherchee) {
			max = indice;
		}
		i++;
	} while (valeurProposee != valeurRecherchee && i<taille);
	if (valeurProposee != valeurRecherchee)
	{
		printf("Votre valeur n'est pas dans le tableau \n");
	}
	else
	{
		printf("Votre valeur ce trouve a l'indice : %d\n", indice);
	}

	system("pause");

	return 0;
}