#include <stdio.h>
#include <string.h>
#include "primality.h"

#define USAGE \
"Utilisation: ./isprime [TEST] [N] [K]\n" \
"Tester la primalité d'un grand nombre.\n\n" \
"  [N]     le nombre à vérifier\n" \
"  [K]     le nombre maximum d'itérations > 0\n" \
"  [TEST]  choisir parmi:\n" \
"            -f  Utiliser le test de primalité de Fermat\n" \
"            -m  Utiliser le test de primalité de Miller-Rabin\n"

int	main(int ac, char **av)
{
	if (ac != 4)
		return !!printf(USAGE);
	mpz_t n;
	unsigned long k;
	bool use_fermat, is_prime = false;

	// Parsing des arguments
	mpz_inits(n, NULL);
	use_fermat = !strcmp(av[1], "-f");
	if ((!use_fermat && strcmp(av[1], "-m"))
	|| gmp_sscanf(av[2], "%Zd", n) != 1
	|| sscanf(av[3], "%lu", &k) != 1
	|| k < 1)
		return !!printf(USAGE);

	// Tests de primalité (si > 1)
	if (mpz_cmp_ui(n, 1) > 0)
		is_prime = use_fermat ? fermat(n, k) : miller_rabin(n, k);
	mpz_clears(n, NULL);

	// Résultat
	printf("%s\n", (is_prime ? "true" : "false"));
	return (0);
}
