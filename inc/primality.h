#ifndef PRIMALITY_H
# define PRIMALITY_H
# include <gmp.h>
# include <stdbool.h>

/*
** Effectue l'opération r = a^h mod n
** Note: h doit être strictement positif
*/
void square_and_multiply(mpz_t r, const mpz_t a, const mpz_t h, const mpz_t n);

/*
** Effectue le test de primalité de Fermat.
** Renvoie vrai si n premier, faux si composé.
** Note: n doit être supérieur à 1 et k supérieur à 0
*/
bool fermat(const mpz_t n, unsigned long k);

/*
** Effectue le test de primalité de Miller-Rabin.
** Renvoie vrai si n premier, faux si composé.
** Note: n doit être supérieur à 1 et k supérieur à 0
*/
bool miller_rabin(const mpz_t n, unsigned long k);

#endif
