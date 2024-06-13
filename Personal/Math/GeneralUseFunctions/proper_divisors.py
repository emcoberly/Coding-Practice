"""
Get proper divisors of a number
"""


def get_proper_divisors(number):
    """
    Gets proper divisors of a number
    """

    proper_divisors = []
    for i in range(1, int(0.5 * number) + 1):
        if number % i == 0:
            proper_divisors.append(i)

    return proper_divisors
