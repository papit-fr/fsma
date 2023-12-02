/*
Square-and-Multiply Algorithm (SMA)

Largely inspired from https://github.com/PhilCR/Cryptography-Square-and-Multiply-modular-Exponentiation
written by Jonathan André Gangi and Philippe Cesar Ramos.
But with small fixes and coding style improvement

@author:
	Christophe Brun

@copyright:
	2023, PapIT SASU

as seen on section 7.4 of Understanding Cryptography:

	Square-and-Multiply for Modular Exponentiation

	Input:  base element x, Exponent h, Modulus n
	Output: y = xˆh mod n
	Initialization: r = x

	Algorithm:
		FORi=t−1DOWNTO0

			r = rˆ2 mod n

			IF hi = 1
				r = r * x mod n

		RETURN (r)

and specified by:
<http://www.moodle.ufscar.br/file.php/4783/Aulas/Aula06/Atividades_sobre_a_teoria_dos_numeros.pdf>
	Input: three integers X, k, N, being 2 <= X, k, N < 2ˆ32.
	Output: one integers Y, as result from its exponentiation

*/

#include <stdio.h>
#include <stdlib.h>

unsigned long sma(unsigned long b, unsigned long exp, unsigned long m)
{
	unsigned long res = 1;

	while (exp > 1)
	{
		if (exp & 1)
		{
			res = (res * b) % m;
		}
		b = (b * b) % m;
		exp >>= 1;
	}

	return (b * res) % m;
}

int main()
{

	unsigned long x, k, n; // input

	unsigned long y; // output

	int input_counter; // return code

	input_counter = scanf("%ld %ld %ld\n", &x, &k, &n); // reading

	if (input_counter != 3)
	{
		fprintf(
			stderr, "Error: invalid input, must be 3, base, exponent and modulo\n");
		exit(EXIT_FAILURE);
	}
	y = sma(x, k, n); // Square-and-Multiply modular Exponentiation

	printf("%ld\n", y);

	return 0;
}
