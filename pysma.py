"""
Largely inspired by https://stackoverflow.com/questions/57668289/implement-the-function-fast-modular-exponentiation
"""
from random import choice, randint

import plotly.graph_objects as go
from numpy import array
from scipy import stats

COLORS = [
    "#" + "".join([choice("0123456789ABCDEF") for j in range(6)]) for i in range(40)
]
CHART_FONT = dict(family="Courier New, monospace", size=18, color="#7f7f7f")


def get_a_random_color():
    return COLORS[randint(0, len(COLORS) - 1)]


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


def count_fsma_exit(base, exp, m):
    """
    Count the exit when remainder is 0.

       :param base: The base
       :param exp: The exponent
       :param m: The modulo
       :return: A integer representing the result of the modular exponentiation
    """
    count_exit = 0
    count_all = 0

    def fsma(b, exp, m):
        """
        Return a stored value when the temporary is 0.

           :param b: The base
           :param exp: The exponent
           :param m: The modulo
           :return: A integer representing the result of the modular exponentiation
        """
        nonlocal count_exit

        res = 1
        while exp > 1:
            buf = res
            if exp & 1:
                res = (res * b) % m
                if res == 0:
                    count_exit += 1
                    return (b * buf) % m
            b = b ** 2 % m
            exp >>= 1
        return (b * res) % m

    fsma(base, exp, m)
    return count_exit


if __name__ == "__main__":
    # Use test function
    from utils import test_function

    test_function(fsma)


def greater_base():
    """
    Return the frequency of a premature exit, function of the base.
    """

    # Plot the above list a Plotly chart
    base_fig = go.Figure()
    mod_fig = go.Figure()
    intercepts = []
    mods = [3, 5, 9, 13, 25, 27, 29, 33, 40, 47, 54, 73, 81, 99, 109, 123, 134, 154]
    for mod in mods:
        exp, freq, mod = compute_freq(mod=mod)
        x = array([x[0] for x in freq])
        y = array([x[1] for x in freq])

        # Generated linear fit
        slope, intercept, r_value, p_value, std_err = stats.linregress(x, y)
        intercepts.append(intercept)
        line = slope * x + intercept
        color = get_a_random_color()
        base_fig.add_trace(
            go.Scatter(
                x=x,
                y=line,
                mode="lines",
                name="mod %s" % mod,
                fillcolor=color,
            )
        )
    # Plot function of base
    base_fig.update_layout(
        title="Premature exit with greater base, exponent {}".format(exp),
        xaxis_title="Base",
        yaxis_range=[0, 0.5],
        yaxis_title="Premature exit frequency",
        font=CHART_FONT,
    )
    # Plot the intercept function of the modulo in mod_fig
    mod_fig.add_trace(
        go.Scatter(
            x=mods,
            y=intercepts,
            mode="lines",
            name="intercept",
            fillcolor="blue",
        )
    )
    mod_fig.update_layout(
        title="Premature exit with greater modulo, exponent {}".format(exp),
        xaxis_title="Modulo",
        yaxis_title="Premature exit frequency",
        font=CHART_FONT,
    )

    return freq, base_fig, mod_fig


def compute_freq(starting_base=970, exp=254345856791354, mod=3):
    """
    Compute the frequency of premature exit for a given base, exponent and modulo.

       :param starting_base: The minimum base to start with
       :param exp: The exponent
       :param mod: The modulo
       :return: A tuple made of the exponent, the frequency and the modulo.
    """
    results = []
    for base in range(starting_base, 97173):
        results.append((base, count_fsma_exit(base, exp, mod)))
    freq = []
    buffer = 0
    interval = 100
    for i, result in enumerate(results):
        buffer += result[1]
        if i % interval == 0:
            freq.append((starting_base + i, (buffer / interval)))
            buffer = 0
    # Remove the first element
    freq.pop(0)
    # Turn the list to a tuple
    freq = tuple(freq)
    return exp, freq, mod
