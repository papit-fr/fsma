/*
Fast-Square-and-Multiply Algorithm (FSMA)

Same as the SMA but store the temporary modular result in a buffer and return it
if the next modular result is 0, after the first squared to manage case where the first
result is zero.

Return sooner surely means faster.

The SMA was largely inspired from https://github.com/PhilCR/Cryptography-Square-and-Multiply-modular-Exponentiation
written by Jonathan André Gangi and Philippe Cesar Ramos.
But with small fixes and coding style improvement

@author:
	Christophe Brun

@copyright:
	2023, PapTI SASU

as seen on section 7.4 of Understanding Cryptography:

	Square-and-Multiply for Modular Exponentiation

	Input:  base element x, Exponent H, Modulus n
	Output: Y = xˆH mod n
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
#include <stdbool.h>
unsigned long fsma(
	unsigned long x, unsigned long h, unsigned long n)
{

	unsigned long r;
	unsigned long b; // A buffer saving the previous r
	int bin[32];
	int i;

	r = x;
	i = 0;

	/* Converts H in Binary */
	while (h > 0)
	{

		if (h % 2 == 0)
		{
			bin[i] = 0;
		}
		else
		{
			bin[i] = 1;
		}

		h = h / 2;
		i++;
	}

	i--; // t-1
	// Boolean flag, after first scare, it will be true
	bool square = false;
	while (i > 0)
	{
		b = r;
		r = (r * r) % n;
		if (r == 0)
		{
			if (square == true)
			{
				return b;
			}
			// first square, so it is not possible to return
			return 0;
		}
		else
		{
			if (bin[--i] == 1)
			{
				b = r;
				r = (r * x) % n;
				// Cannot return here with b, it is always done above
			}
		}
		square = true;
	}

	return r;
}

int main()
{

	unsigned long x, k, n; // input

	unsigned long y; // output

	scanf("%ld %ld %ld\n", &x, &k, &n); // reading

	y = fsma(x, k, n); // Square-and-Multiply modular Exponentiation

	printf("%ld\n", y);

	return 0;
}