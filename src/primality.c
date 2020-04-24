#include "primality.h"

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

bool fermat(const mpz_t n, unsigned long k, gmp_randstate_t state)
{
	mpz_t n1, a, r;

	mpz_inits(n1, a, r, NULL);
	mpz_sub_ui(n1, n, 1); // n1 = n - 1

	// Test de primalité
	while (k)
	{
		mpz_urandomm(a, state, n1); // rand % n - 1
		mpz_add_ui(a, a, 1); // ++a (car a > 0)
		square_and_multiply(r, a, n1, n); // r = a^(n - 1) mod n
		if (mpz_cmp_ui(r, 1)) // r != 1 ?
			break ; // n est composé
		--k;
	}
	mpz_clears(n1, a, r, NULL);
	return (!k);
}

bool miller_rabin(const mpz_t n, unsigned long k, gmp_randstate_t state)
{
	mp_bitcnt_t s0, j;
	mpz_t n1, s, t, y, a;

	mpz_inits(n1, s, t, y, a, NULL);
	mpz_sub_ui(n1, n, 1); // n1 = n - 1

	// Décomposition sous la forme n - 1 = 2^s * t
	s0 = mpz_scan1(n1, 0); // s0 = position du premier 1 dans n - 1 en base 2
	mpz_set_ui(s, s0); // s = s0 (conversion en mpz_t)
	mpz_set_ui(a, 2); // a = 2
	square_and_multiply(y, a, s, n); // y = 2^s mod n
	mpz_divexact(t, n1, y); // t = (n - 1) / y

	// Test de primalité
	while (k)
	{
		mpz_urandomm(a, state, n1); // rand % n - 1
		mpz_add_ui(a, a, 1); // ++a (car a > 0)
		square_and_multiply(y, a, t, n); // y = a^t mod n
		if (mpz_cmp_ui(y, 1) && mpz_cmp(y, n1)) // y != 1 && y != n1 ?
		{
			for (j = 0; j < s0; ++j)
			{
				mpz_mul(y, y, y); // y = y²
				mpz_mod(y, y, n); // y = y mod n
				if (!mpz_cmp_ui(y, 1)) // y == 1 mod n ?
					j = s0;
				else if (!mpz_cmp(y, n1)) // y == -1 mod n ?
					break ;
			}
			if (j >= s0)
				break ; // n est composé
		}
		--k;
	}
	mpz_clears(n1, s, t, y, a, NULL);
	return (!k);
}
