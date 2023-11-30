/*
Square-and-Multiply Algorithm (SMA)

Largely inspired from https://github.com/PhilCR/Cryptography-Square-and-Multiply-modular-Exponentiation
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

unsigned long sma(unsigned long x, unsigned long h, unsigned long n)
{

	unsigned long r;
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

	while (i > 0)
	{

		r = (r * r) % n;

		if (bin[--i] == 1)
		{
			r = (r * x) % n;
		}
	}
	return r;
}

int main()
{

	unsigned long X, k, N; // input

	unsigned long Y; // output

	scanf("%ld %ld %ld\n", &X, &k, &N); // reading

	Y = sma(X, k, N); // Square-and-Multiply modular Exponentiation

	printf("%ld\n", Y);

	return 0;
}
