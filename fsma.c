// Include and defines
#include <stdint.h>

/*******************************************************************************
 * Fast-Square-and-Multiply Algorithm (FSMA)
 *
 *
 * Same as the SMA but return 0 modular result is 0, after the first squared to
 * manage case where the first result is zero.
 *
 * Return sooner surely means faster.
 *
 * as seen on section 7.4 of Understanding Cryptography:
 *
 * 	Square-and-Multiply for Modular Exponentiation
 *
 * 	Input:  base element x, Exponent h, Modulus n
 * 	Output: y = xˆh mod n
 * 	Initialization: r = x
 *
 * 	Algorithm:
 * 		FORi=t−1DOWNTO0
 *
 * 			r = rˆ2 mod n
 *
 * 			IF hi = 1
 * 				r = r * x mod n
 *
 * 		RETURN (r)
 *
 * @author Christophe Brun, PapIT SASU
 * @date 2023-12-01
 * @copyright PapIT SASU
 * @see Understanding Cryptography, section 7.4
 *
 * @param base base element x
 * @param exp Exponent h
 * @param mod Modulus n
 * @return y = xˆh mod n
 */
uint64_t fsma(uint64_t base, uint64_t exp, uint64_t mod) {
    uint64_t res = 1;

    while (exp > 1) {

        // If the exponent digit is 1, then multiply
        if (exp & 1) {
            res = (res * base) % mod;

            // If an intermediate result is zero, we can return 0.
            // The result will be zero anyway
            if (res == 0) {
                return 0;
            }
        }

        // If the exponent digit is 0, then square
        base = (base * base) % mod;
        exp >>= 1;
    }

    return (base * res) % mod;
}