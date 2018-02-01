#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
void avancer(int *);
void lancer(int *, int *);

int main() {
	srand(time(NULL));
	int joueur[3] = { 0,0,0 };

	avancer(joueur);
	printf("J1 - %d \n", joueur[0]);
	printf("J2 - %d \n", joueur[1]);
	printf("J3 - %d \n", joueur[2]);
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

			if (*(pion + i) == 0 && (de1 == 6 && de2 == 3) || (de1 == 3 && de2 == 6))
			{
 				printf("J %d vous avez fait un lancez 6 et 3 allez a la case 26 ", i+1);
				*(pion + i) = 26;
			}
			else if (*(pion + i) == 0 && ((de1 == 5 && de2 == 4) || (de1 == 4 && de2 == 5)) ) {
				printf("J %d vous avez fait un lancez 5 et 4 allez a la case 53 \n", i + 1);
				*(pion + i) = 53;
			}
			else if (prison != pion + i && puit != pion + i)
			{
				*(pion + i) = *(pion + i) + de1 + de2;
				printf("J %d a fait %d \n", i + 1, de1 + de2);
			}

			if (*(pion + i) % 9 == 0 && *(pion + i) != 63)
			{
				printf("J %d Vous etes tomber sur une case qui est un mutliple de 9 avancer encore de %d \n", i + 1, de1 + de2);
				*(pion + i) = *(pion + i) + de1 + de2;
			}
			else if (*(pion + i) == 6)
			{
				printf("J %d allez a la case 12 \n", i + 1);

				*(pion + i) = 12;
			}
			else if (*(pion + i) == 42)
			{
				printf("J %d retourner a la case 30 \n", i + 1);
				*(pion + i) = 30;
			}
			else if (*(pion + i) == 58)
			{
				printf("J %d vous etes mort retourner a la case de départ \n", i + 1);

				*(pion + i) = 0;
			}
			else if (*(pion + i) == 31)
			{
				printf("J %d vous etes tomber dans le puit. Attendez que quelqu'un vous remplace \n", i + 1);
				puit = pion + i;
			}
			else if (*(pion + i) == 52)
			{
				if (prison == NULL)
				{
					printf("J %d Vous etes en prison \n", i + 1);
					prison = pion + i;
				}
				else if (prison != pion + i)
				{
					prison == NULL;
				}

				else
				{
					printf("J %d Vous etes toujours en prison \n", i + 1);
				}
				puit = pion + i;
			}
			else if (*(pion + i) > 63)
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

}