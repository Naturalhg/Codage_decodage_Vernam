#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include "fonctions.h"



int generate(int count, int argc,char *argv[])
{
	FILE *f;
	char cle[count];
	int a,i;
	char characteres[26]="azertyuiopqsdfghjklmwxcvbn";
	srand(time(NULL));
	

	//Crée la nouvelle clé à partir du nombre de caractères du message
	for(a=0;a<(count-2);a++)
	{
		i = rand()%26;
		cle[a]=characteres[i];
	}

	for (a=1;a<3;a++)
	{
		i = rand()%26;
		cle[count-a]=characteres[i];
	}
	f = fopen (argv[3], "w");

	//Ecris la clé précédemmant créée dans le fichier cle.txt par exemple
    if (f)
    {
        fwrite (cle, sizeof(char), count, f);
    } 
    else 
    {
        return EXIT_FAILURE;
    }
    fclose (f);
	return EXIT_SUCCESS;
}