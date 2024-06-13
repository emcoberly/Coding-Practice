"""
Returns a list of prime factors
"""


def prime_factors(number):
    """
    Returns a list of prime factors of 'number'
    """

    with open("primes.txt", "r", encoding="UTF-8") as f:
        lines = f.readlines()
        primes = [int(line.strip()) for line in lines]

    factors = []
    for i in primes:
        while number % i == 0:
            factors.append(i)
            number /= i
        if number == 1:
            break

    return factors
