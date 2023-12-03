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

*/
#include <stdio.h>
#include <stdlib.h>

unsigned long long fsma(unsigned long long base, unsigned long long exp, unsigned long long mod) {
    unsigned long long res = 1;

    while (exp > 1) {
        unsigned long long buf = res;

        if (exp & 1) {
            res = (res * base) % mod;

            if (res == 0) {
                return (base * buf) % mod;
            }
        }

        base = (base * base) % mod;
        exp >>= 1;
    }

    return (base * res) % mod;
}

int main() {

    unsigned long long base, exp, mod; // input

    unsigned long long x; // output

    int input_counter; // number of input read

    input_counter = scanf("%llu %llu %llu\n", &base, &exp, &mod); // reading

    if (input_counter != 3) {
        fprintf(
                stderr, "Error: invalid input, must be 3, base, exponent and modulo\n");
        exit(EXIT_FAILURE);
    }
    x = fsma(base, exp, mod); // Square-and-Multiply modular Exponentiation

    printf("%llu\n", x);

    return 0;
}