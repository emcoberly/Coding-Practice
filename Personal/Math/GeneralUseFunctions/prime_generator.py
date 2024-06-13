"""
Generates a list of prime numbers
"""

import os

import get_integer
import proper_divisors


def generate_primes(number):
    """
    Generates a file of primes up to 'number'
    """
    primes = []
    for i in range(2, number + 1):
        prime = proper_divisors.get_proper_divisors(i)
        if len(prime) == 1:
            primes.append(i)

    with open("primes.txt", "w", encoding="UTF-8") as f:
        for prime in primes:
            f.write(str(prime) + "\n")


def main():
    """
    Main function
    """

    user_input = get_integer.get_integer()
    generate_primes(user_input)
    os.system("cls" if os.name == "nt" else "clear")


if __name__ == "__main__":
    main()
