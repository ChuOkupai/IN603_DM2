#include "primtest.h"

int	main(int ac, char **av)
{
	(void)ac;
	(void)av;
	mpz_t r, a, h, n;
	mpz_inits(r, a, h, n, NULL);
	mpz_add_ui(a, a, 2);
	mpz_add_ui(h, h, 26);
	mpz_add_ui(n, n, 10000000000);
	square_and_multiply(r, a, h, n);
	gmp_printf("r = %Zd\n", r);
	mpz_clears(r, a, h, n, NULL);
	return (0);
}
