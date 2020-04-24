IN603 - DM : Tests de primalité de Fermat et de Miller-Rabin

Auteur : SOURSOU Adrien
Date   : Avril 2020

* Conseils d'utilisation :

Pour compiler les fichiers, un Makefile est mis à disposition.
Il suffit de lancer la commande `make` dans un terminal.

Tests fournis :
La commande `make test` contient quelques tests pour vérifier le bon
fonctionnement du programme.

Le binaire nommé "isprime" se trouve à la racine du répertoire.
Il peut être exécuté suivant ce format :
	$> ./isprime [algorithme] [n] [k]

Liste des paramètres :
- [algorithme] : l'algorithme à utiliser, "fermat" ou "miller-rabin"
- [n] : l'entier à tester
- [k] : le nombre d'itérations

Exemples d'utilisation :
	$> ./isprime fermat 483565828561 10000
	$> ./isprime miller-rabin 3835729783 50000

* Remarques :

- La documentation des fonctions implémentées est disponible dans inc/primality.h.
- Le code source détaillé des fonctions est dans src/primality.c.
- Le main est trouvable dans src/main.c, cependant il n'est pas très intéressant,
il contient le parsing des paramètres entrés par l'utilisateur.
