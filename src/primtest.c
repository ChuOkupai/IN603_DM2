#include "primtest.h"

void	square_and_multiply(mpz_t r, mpz_t a, mpz_t h, mpz_t n)
{
	mp_bitcnt_t i = mpz_sizeinbase(h, 2) - 1;
	if (!i)
	{
		mpz_set_ui(r, 1);
		return ;
	}
	mpz_add_ui(r, a, 0);
	while (i--)
	{
		mpz_mul(r, r, r);
		mpz_mod(r, r, n);
		if (mpz_tstbit(h, i))
		{
			mpz_mul(r, r, a);
			mpz_mod(r, r, n);
		}
	}
}
