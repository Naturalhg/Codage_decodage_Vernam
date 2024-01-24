/* 
			Decodage du message 
	On ecrit un programme qui à partir d'un fichier message_code et 
	d'un fichier clé produira un fichier message_decode
*/

#include <stdio.h>
#include <stdlib.h>

int decodage(int argc, char *argv[]) {
	FILE *f_m, *f_k, *f_mdc; /* strcutures permettant, une fois FOPEN 
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
	
	char * cheminFic_mdc = argv[4];
	f_mdc = fopen(cheminFic_mdc, "w");
	if (f_mdc==NULL)
	{
		printf("Echec de l'ouverture du fichier.\n");
	}
	

	//	Boucle : calcul permettant de decoder un caractère puis l'écrire dans le 
	//	fichier f_mdc
	while ((c = fgetc(f_m)) != EOF)
	{
		k1 = fgetc(f_k);
		calcul = c-k1 >= 0?c-k1:256-(c-k1);
		fputc(calcul, f_mdc);
	}
	
	//fermeture des fichiers
	fclose(f_m);
	fclose(f_k);
	fclose(f_mdc);
	
	return 1;
	
}