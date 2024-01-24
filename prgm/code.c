#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "fonctions.h"

int main(int argc, char *argv[]) {
	FILE *f_m, *f_k, *f_mc; /* strcutures permettant, une fois FOPEN 
	exécuté de recupérer des informations pour manipuler les fichiers
	en C */
	char * cheminFic_m = argv[2];
	int c,count=0;
	

	/* recupération sur la ligne de commande des noms de fichiers et option (-c pour 
		codage, -d pour décodage) : message cle message_calculé 
	
	./code -c f1 f2 f3
	./code -d f1 f2 f3
	
	*/

	//	Si l'option donnée en premier argument est "-c", alors on génère une clé 
	//	aléatoirement et on code le message avec
	if(strcmp(argv[1], "-c")==0)
	{
		//	Parcours le fichier du message à coder pour connaitre le nombre de caractères présents.
		f_m = fopen(cheminFic_m, "r");
		if(f_m==NULL)
		{
			return EXIT_FAILURE;
		}
		for (c = getc(f_m); c != EOF; c = getc(f_m))
		{
		    count = count + 1;
		}

		// Génère une clé aléatoire
		generate(count, argc, argv);

		//	Code le message
		codage(argc, argv);
	}

	/*	Si l'option donée en premier argument est "-d", alors on décode le message
		donné en 2eme argument en mettant le résultat dans un nouveau fichier nommé 
		en 4eme argument
	*/
	else if(strcmp(argv[1], "-d")==0)
	{
		//	Décode le message codé
		decodage(argc, argv);
	}
	return EXIT_SUCCESS;
}