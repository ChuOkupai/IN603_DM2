#include <sys/types.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include "primality.h"

#define USAGE \
"Utilisation: ./isprime algorithm n k\n" \
"Tester la primalité d'un grand nombre.\n\n" \
"  algorithm  l'algorithme à utiliser (fermat ou miller-rabin)\n" \
"  n          l'entier à tester\n" \
"  k          le nombre maximum d'itérations > 0\n"

int	main(int ac, char **av)
{
	if (ac != 4) // Besoin de 3 arguments
		return !!printf(USAGE);
	gmp_randstate_t state;
	mpz_t n;
	long k;
	bool use_fermat, is_prime = false;

	// Parsing des arguments
	mpz_init(n);
	use_fermat = !strcmp(av[1], "fermat");
	if ((!use_fermat && strcmp(av[1], "miller-rabin"))
	|| gmp_sscanf(av[2], "%Zd", n) != 1
	|| sscanf(av[3], "%ld", &k) != 1
	|| k < 1)
	{
		mpz_clear(n);
		return !!printf(USAGE);
	}

	// Tests de primalité
	if (mpz_cmp_ui(n, 1) > 0) // n > 1 ?
	{
		gmp_randinit_mt(state);
		gmp_randseed_ui(state, getpid()); // génération du seed
		if (use_fermat)
			is_prime = fermat(n, k, state);
		else if (mpz_tstbit(n, 0))
			is_prime = miller_rabin(n, k, state);
		else // Miller-Rabin avec n pair
			return !!printf("erreur: le test de primalité de Miller-Rabin a"
			" besoin d'un nombre impair\n");
		gmp_randclear(state);
	}
	mpz_clear(n);

	// Affichage du résultat
	printf("%s\n", (is_prime ? "true" : "false"));
	return (0);
}
