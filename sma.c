/*
Square-and-Multiply Algorithm (SMA)

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

*/

#include <stdio.h>
#include <stdlib.h>
// include stdint.h for standard width integer
#include <stdint.h>

uint64_t sma(uint64_t base, uint64_t exp, uint64_t mod) {
    uint64_t res = 1;

    while (exp > 1) {
        if (exp & 1) {
            res = (res * base) % mod;
        }
        base = (base * base) % mod;
        exp >>= 1;
    }

    return (base * res) % mod;
}

int main() {

    uint64_t base, exp, mod; // input

    uint64_t x; // output

    int input_counter; // number of input read

    input_counter = scanf("%lu %lu %lu\n", &base, &exp, &mod); // reading

    if (input_counter != 3) {
        fprintf(
                stderr, "Error: invalid input, must be 3, base, exponent and modulo\n");
        exit(EXIT_FAILURE);
    }
    x = sma(base, exp, mod); // Square-and-Multiply modular Exponentiation

    printf("%lu\n", x);

    return 0;
}
