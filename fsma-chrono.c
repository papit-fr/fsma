
#include <stdio.h>
#include <time.h>
#include "fsma.h"
#include "utils.h"

/*******************************************************************************
 * CLI, main function Call the fsma function from fsma.c and use it in a basic CLI.
 * Fail if the input is not 3.
 * A chrono is used to measure the time of the execution of many iterations of the
 * fsma function.
 * It reads the base, exponent and modulo from the standard input and print the result
 * of the fsma function.
 * It aslo print the time of the execution.
 *
 * @see utils.h
 * @return 0
 * @see fsma.h
 * @author Christophe Brun, PapIT SASU
 * @date 2023-12-07
 * @copyright PapIT SASU
 */
int main() {
    uint64_t base, exp, mod; // input
    uint64_t x; // output
    uint16_t input_counter; // number of input read
    clock_t start, end; // chrono
    double cpu_time_used; // chrono
    input_counter = scanf("%lu %lu %lu\n", &base, &exp, &mod); // reading
    check_args_count(input_counter);
    start = clock(); // chrono
    // execution 1000 times the fsma function
    for (uint32_t i = 0; i < iteration; ++i) {
        x = fsma(base, exp, mod); // Square-and-Multiply modular Exponentiation
    }

    end = clock(); // chrono
    cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC; // chrono
    printf("%lu\n", x);
    printf("Time: %f\n", cpu_time_used); // chrono
    return 0;
}