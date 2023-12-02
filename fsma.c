/*
Fast-Square-and-Multiply Algorithm (FSMA)

Same as the SMA but store the temporary modular result in a buffer and return it
if the next modular result is 0, after the first squared to manage case where the first
result is zero.

Return sooner surely means faster.

@author:
	Christophe Brun

@copyright:
	2023, PapIT SASU

as seen on section 7.4 of Understanding Cryptography:

	Square-and-Multiply for Modular Exponentiation

	Input:  base element x, Exponent H, Modulus n
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
unsigned long fsma(unsigned long b, unsigned long exp, unsigned long m)
{
	unsigned long res = 1;

	while (exp > 1)
	{
		unsigned long buf = res;

		if (exp & 1)
		{
			res = (res * b) % m;

			if (res == 0)
			{
				return (b * buf) % m;
			}
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
	y = fsma(x, k, n); // Square-and-Multiply modular Exponentiation

	printf("%ld\n", y);

	return 0;
}