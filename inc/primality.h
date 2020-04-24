#ifndef PRIMALITY_H
# define PRIMALITY_H
# include <gmp.h>
# include <stdbool.h>

/*
** Effectue l'opération r = a^h mod n
** Paramètres :
** - r nombre dans lequel stocker le résultat
** - a nombre positif
** - h nombre strictement positif
** - n modulo
*/
void square_and_multiply(mpz_t r, const mpz_t a, const mpz_t h, const mpz_t n);

/*
** Effectue le test de primalité de Fermat.
** Renvoie vrai si n probablement premier, faux si composé.
** Paramètres :
** - n     nombre à tester (supérieur à 1)
** - k     nombre d'itérations (supérieur à 0)
** - state algorithme de génération de nombres pseudo aléatoires
*/
bool fermat(const mpz_t n, unsigned long k, gmp_randstate_t state);

/*
** Effectue le test de primalité de Miller-Rabin.
** Renvoie vrai si n probablement premier, faux si composé.
** Notes:
** - n     nombre à tester (impair et supérieur ou égal 3)
** - k     nombre d'itérations (supérieur à 0)
** - state algorithme de génération de nombres pseudo aléatoires
*/
bool miller_rabin(const mpz_t n, unsigned long k, gmp_randstate_t state);

#endif
