# Vernam

Ce programme permet de coder et de décoder un message grâce à des fichiers format ".txt"

Il est codé en C et contient un makefile pour faciliter son utilisation(voir instructions ci-dessous)

## Instructions

Tout d'abord, déplacez vous dans le dossier prgm, puis :
	
Pour compiler le programme, il suffit de taper :

	- make

Pour coder votre message, tapez par exemple :

	- ./code -c FichierMessage.txt FichierClé.txt FichierMessageCodé.txt

où le message codé se trouvera dans le fichier "FichierMessageCodé.txt" et le message à coder sera dans le fichier "FichierMessage.txt"

Pour décoder le programme, tapez par exemple :

	- ./code -d FichierMessageCodé.txt FichierClé.txt FichierMessageDécodé.txt
 
où le message décodé pourra être lu dans le fichier "FichierMessageDécodé.txt"

Pour voir le résultat du codage ou du décodage, tapez :

	- less FichierMessageCodé.txt
ou

	- less FichierMessageDécodé.txt

Pour supprimer les exécutables d'extension ".o" et l'exécutable "code", tapez :

	- make clean
 
### Attention : 

- Les fichiers cle.txt et message.txt (par exemple) doivent déjà exister
- Le message doit bien être modifié avant utilisation sur un message précis
- Le message à coder possède une certaine limite, il est donc conseillé de le répartir en plusieurs fichiers s'il est très long

## Feedback

Si vous avez des retours, contactez moi à cette adresse : nolan.toussaint77@gmail.com

## Auteur

- [@Nolan](https://github.com/Naturalhg)

## License

### [GNU GPL License](LICENSE)
