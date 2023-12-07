// include stdint.h for standard width integer
#include <stdint.h>

/*******************************************************************************
 * Square-and-Multiply Algorithm (SMA)
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
