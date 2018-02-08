#include <stdio.h>
#include <stdlib.h>

main() {
	int matchJoue = 0;
	int butMe = 0;
	int butYou = 0;
	int i = 0;
	int dif = 0;
	int matchGagner = 0;

	printf("Saisir le nombre de match joue par votre equipe \n");
	scanf("%d", &matchJoue);

	// si malloc est = 0 alors ca ne marche pas
	int* meEquipe = (int*)malloc(matchJoue * sizeof(int));
	int* youEquipe = (int*)malloc(matchJoue * sizeof(int));

	/* Imperatif de faire le test if(var1 != null && var2 != null){ 
	   Ne pas oublie :  free(var1);
						free(var2);
	}
	else{
			printf("L'allocation dynamique en memoire n'a pas fonctionnee\n");
			system("pause");
		} 
		*/
	if (meEquipe != NULL && youEquipe != NULL) {
		do
		{

			printf("Saisir le nombre de but marque par votre equipe pour le match n %d\n", i + 1);
			scanf("%d", &butMe);
			*(meEquipe + i) = butMe;

			printf("Saisir le nombre de but marque par votre adversairepour le match n %d\n", i + 1);
			scanf("%d", &butYou);

			*(youEquipe + i) = butYou;
			if (dif < butMe - butYou)
			{
				dif = butMe - butYou;
			}
			 if(butMe > butYou) {
				 matchGagner +=1;
			}
			i++;
			system("cls");
		} while (i < matchJoue);

		i = 0;
		while (i < matchJoue)
		{
			printf("%d | ", *(meEquipe + i));
			i++;
		}
		printf("\n");
		i = 0;
		while (i < matchJoue)
		{
			printf("%d | ", *(youEquipe + i));
			i++;
		}

		system("pause");
		system("cls");
		free(meEquipe);
		free(youEquipe);

		if (dif != 0)
		{
			printf("Votre meilleur score est : %d et vous avez gagner %d\n", dif, matchGagner);
			
		}
		else
		{
			printf("Vous etes des merde vous n'avez pas gagner un seul match alors que vous en avez fait %d\n", matchJoue);
		}
		system("pause");
	}

	else {
		printf("L'allocation dynamique en memoire n'a pas fonctionnee\n");
		system("pause");
	}
	return 0;
}