#include <stdio.h>
#include <stdlib.h>
char *strdup(char *);
int main() {
	int i = 0;
	char chaine[30] = "bonjour";
	char *newChaine = strdup(chaine);
	while (*(newChaine + i) != '\0')
	{
		printf("%c", *(newChaine + i));
		i++;
	}
	system("pause");
	return 0;

}

char *strdup(char *pchaine) {
	int size = 1;
	int i = 0;

	do
	{
		size++;
	} while (*(pchaine + size) != '\0');
	char* newchaine = (char *)malloc(size, sizeof(char));
	if (newchaine != NULL)
	{    
		do
		{
			*(newchaine + i) = *(pchaine + i);
			i++;
		} while (i < size);
		return newchaine;
	}
	else
	{
		printf("error");
	}


};