#include "primality.h"

/*
** Effectue l'opération r = a^h mod n
** Note: h doit être strictement positif
*/
void square_and_multiply(mpz_t r, const mpz_t a, const mpz_t h, const mpz_t n)
{
	mp_bitcnt_t i = mpz_sizeinbase(h, 2) - 1;
	mpz_add_ui(r, a, 0); // r = a
	while (i)
	{
		mpz_mul(r, r, r); // r = r²
		if (mpz_tstbit(h, --i)) // hi = 1
			mpz_mul(r, r, a); // r = r * a
		mpz_mod(r, r, n); // r = r mod n
	}
}

/*
** Effectue le test de primalité de Fermat.
** Renvoie vrai si n premier, faux si composé.
** Note: n doit être supérieur à 1 et k supérieur à 0
*/
bool fermat(const mpz_t n, unsigned long k)
{
	gmp_randstate_t state;
	mpz_t a, n1, r;
	bool prime = true;

	gmp_randinit_mt(state); // seed
	mpz_inits(a, n1, r, NULL);
	mpz_sub_ui(n1, n, 1); // n1 = n - 1
	while (k--)
	{
		mpz_urandomm(a, state, n1); // rand % n - 1
		mpz_add_ui(a, a, 1); // ++a (car a > 0)
		square_and_multiply(r, a, n1, n);
		if (mpz_cmp_ui(r, 1)) // r != 1 ?
		{
			prime = false; // n est composé
			break ;
		}
	}
	gmp_randclear(state);
	mpz_clears(a, n1, r, NULL);
	return (prime);
}

/*
** Effectue le test de primalité de Miller-Rabin.
** Renvoie vrai si n premier, faux si composé.
** Note: n doit être supérieur à 1 et k supérieur à 0
*/
bool miller_rabin(const mpz_t n, unsigned long k)
{
	(void)n;
	(void)k;
	return (false);
}
