#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "GestionCas.h"
void avancer(int *);
void lancer(int *, int *);


int main() {
	srand(time(NULL));
	int joueur[3] = { 0,0,0 };

	avancer(joueur);
	system("pause");
	return 0;
}
void lancer(int *de1, int *de2) {
	*de1 = rand() % (6 - 1) + 1;
	*de2 = rand() % (6 - 1) + 1;
}
void avancer(int *pion) {
	int de1;
	int de2;
	int i = 0;
	int * puit = NULL;
	int * prison = NULL;
	do
	{
		if (i < 3) {
			lancer(&de1, &de2);
			if (*(pion + i) == 0)
			{
				casDepart(de1,de2,i,pion);
			}
			else if (prison != pion + i && puit != pion + i)
			{
				*(pion + i) = *(pion + i) + de1 + de2;
				printf("J %d a fait %d \n", i + 1, de1 + de2);
			}

			casParticulier(pion, i, de1, de2);
			casPuit_Prison(pion, prison, puit, i);
			if (*(pion + i) > 63)
			{
				*(pion + i) = 63 - (*(pion + i) - 63);
				printf("J %d Vous avez depasser 63 allez a la case %d \n", i + 1, *(pion + i));
			}

			i++;
		}
		else
		{
			i = 0;
		}
		printf("J1 - %d \n", *(pion + 0));
		printf("J2 - %d \n", *(pion + 1));
		printf("J3 - %d \n", *(pion + 2));
		system("pause");
		system("cls");
	} while (*(pion + i - 1) < 63);
	printf("J%d - A gagner \n", i - 1);

}
