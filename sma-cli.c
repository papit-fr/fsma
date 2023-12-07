#include <stdio.h>
#include "sma.h"
#include "utils.h"

/*******************************************************************************
 * CLI, main function Call the sma function from sma.c and use it in a basic CLI.
 * Fail if the input is not 3.
 * It reads the base, exponent and modulo from the standard input and print the result
 * of the sma function.
 * @return 0
 * @see sma.h
 * @author Christophe Brun, PapIT SASU
 * @date 2023-12-07
 * @copyright PapIT SASU
 */
int main() {
    uint64_t base, exp, mod; // input
    uint64_t x; // output
    uint16_t input_counter; // number of input read
    input_counter = scanf("%lu %lu %lu\n", &base, &exp, &mod); // reading
    check_args_count(input_counter);
    x = sma(base, exp, mod); // Square-and-Multiply modular Exponentiation
    printf("%lu\n", x);
    return 0;
}