"""
Largely inspired by https://stackoverflow.com/questions/57668289/implement-the-function-fast-modular-exponentiation
"""


def sma(b, exp, m):
    """
    Return a stored value when the temporary is 0.

       :param b: The base
       :param exp: The exponent
       :param m: The modulo
       :return: A integer representing the result of the modular exponentiation
    """
    res = 1
    while exp > 1:
        if exp & 1:
            res = (res * b) % m
        b = b ** 2 % m
        exp >>= 1
    return (b * res) % m


def fsma(b, exp, m):
    """
    Return a stored value when the temporary is 0.

       :param b: The base
       :param exp: The exponent
       :param m: The modulo
       :return: A integer representing the result of the modular exponentiation
    """
    res = 1
    while exp > 1:
        buf = res
        if exp & 1:
            res = (res * b) % m
            if res == 0:
                return (b * buf) % m
        b = b ** 2 % m
        exp >>= 1
    return (b * res) % m


if __name__ == "__main__":
    # Use test function
    from utils import test_function

    test_function(fsma)
