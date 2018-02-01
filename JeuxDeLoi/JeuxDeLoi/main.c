#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
int main(){
	srand(time(NULL));
	char joueur[3] = { 0,0,0 };
	


	avancer(joueur);
	return 0;
}
void lancer(int *de1, int *de2) {
	int *de1 = rand() % (6 - 1) + 1;
	int *de2 = rand() % (6 - 1) + 1;
}
void avancer(char *pion) {
	int de1;
	int de2;
	int i = 0;
	while (i>3)
	{
		lancer(&de1, &de2);
	}
	
}