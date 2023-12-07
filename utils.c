// Includes and defines
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

/*******************************************************************************
 * Check the number of arguments. Fail if the number of arguments is not 3.
 * The 3 arguments are the base, the exponent and the modulo.
 *
 * @author Christophe Brun, PapIT SASU
 * @date 2023-12-07
 * @copyright PapIT SASU
 */
void check_args_count(uint16_t argc) {
    if (argc != 3) {
        fprintf(stderr, "Error: invalid number of arguments, must be 3, base, exponent and modulo\n");
        exit(EXIT_FAILURE);
    }
}