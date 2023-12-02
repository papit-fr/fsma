import logging

logging.basicConfig(
    format='%(asctime)s %(message)s',
    encoding='utf-8',
    level=logging.INFO
)
# C type max values, https://zestedesavoir.com/tutoriels/755/le-langage-c-1/notions-avancees/les-limites-des-types/
MAX_C_UNSIGNED_LONG = 4294967295
# Test suite template
BASE = 970397
EXPONENT = 98725745
MODULO = 98


def test_function(callable_function):
    """
    Test function can be used to test any function that takes 3 unsigned long
    integers and return an unsigned long integer.
    """
    # From 2 to the max the C unsigned long can hold
    logging.info("Testing function starting...")
    for c_integer in range(20, MAX_C_UNSIGNED_LONG, 1):
        assert pow(c_integer, EXPONENT, MODULO) == callable_function(
            c_integer, EXPONENT, MODULO
        ), f"{c_integer} ** {EXPONENT} % {MODULO} != {callable_function(c_integer, EXPONENT, MODULO)}"
        assert pow(BASE, c_integer, MODULO) == callable_function(
            BASE, c_integer, MODULO
        ), f"{BASE} ** {c_integer} % {MODULO} != {callable_function(BASE, c_integer, MODULO)}"
        assert pow(BASE, EXPONENT, c_integer) == callable_function(
            BASE, EXPONENT, c_integer
        ), f"{BASE} ** {EXPONENT} % {c_integer} != {callable_function(BASE, EXPONENT, c_integer)}"
    logging.info(f"Greater modulo computed is {BASE} ** {c_integer} % {MODULO}")
    logging.info("Testing function finished successfully!")
