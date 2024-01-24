/* 
			Codage du message 
	On ecrit un programme qui à partir d'un fichier message et 
	d'un fichier clé produira un fichier message_code
*/

#include <stdio.h>
#include <stdlib.h>
#include "fonctions.h"

int codage(int argc, char *argv[]) {
	FILE *f_m, *f_k, *f_mc; /* strcutures permettant, une fois FOPEN 
	exécuté de recupérer des informations pour manipuler les fichiers
	en C */
	
	int c;
	int k1;
	int calcul;
	
	//	Ouverture des fichiers et vérification d'erreurs d'ouverture
	
	char * cheminFic_m = argv[2];
	f_m = fopen(cheminFic_m, "r");
	if (f_m==NULL)
	{
		printf("Echec de l'ouverture du fichier.\n");
	}

	char * cheminFic_k = argv[3];
	f_k = fopen(cheminFic_k, "r");
	if (f_k==NULL)
	{
		printf("Echec de l'ouverture du fichier.\n");
	}

	char * cheminFic_mc = argv[4];
	f_mc = fopen(cheminFic_mc, "w");
	if (f_mc==NULL)
	{
		printf("Echec de l'ouverture du fichier.\n");
	}
	
	//	Boucle : calcul permettant de coder un caractère puis l'écrire dans le 
	//	fichier f_m
	while ((c = fgetc(f_m)) != EOF)
	{
		k1 = fgetc(f_k);
		calcul = (c+k1) % 256;
		fputc(calcul, f_mc);
	}
	
	//	Fermeture des fichiers
	fclose(f_m);
	fclose(f_k);
	fclose(f_mc);
	
	return EXIT_SUCCESS;
	
}