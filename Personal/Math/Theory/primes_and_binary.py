"""
Converts primes to binary and adds the powers of 2
"""

import matplotlib.pyplot as plt


def get_power_sum(binary_number):
    """
    Sums the powers of 2 in a binary number

    :param binary_number: binary number as a string
    """

    powers_of_2 = 0
    for i, bit in enumerate(binary_number):
        if bit == "1":
            powers_of_2 += len(binary_number) - i - 1
    return powers_of_2


def prime_scan(prime_list):
    """
    Checks a preset list of primes and outputs tuples of primes and their power sums
    """

    just_sums = []
    primes_and_sums = []

    power_sum = 0
    for prime in prime_list:
        power_sum = get_power_sum(str(bin(prime)))
        just_sums.append(power_sum)
        primes_and_sums.append((prime, power_sum))

    ##### print(primes_and_sums)

    plt.plot(prime_list, just_sums, marker="o", markersize=1.5)
    plt.show()


def is_prime(num):
    """
    Checks if a given number is prime.
    A prime number is a natural number greater than 1 that has no positive divisors other than 1 and itself.
    """
    if num < 2:
        return False
    # Check for divisibility from 2 up to the square root of the number
    # Any factor larger than the square root would have a corresponding smaller factor already checked
    for i in range(2, int(num**0.5) + 1):
        if num % i == 0:
            return False
    return True


def get_prime_list(limit):
    """
    Generates a list of prime numbers up to a specified limit (inclusive).
    """
    primes = []
    for number in range(2, limit + 1):
        if is_prime(number):
            primes.append(number)
    return primes


def main():
    """
    Main function
    """

    decision = input("Would you like to check a specific prime number? Y/N -> ")
    if decision in ("y", "Y"):
        # Get prime number
        prime = int(input("Enter a prime number: "))

        # Convert prime to binary string
        bin_prime = str(bin(prime))

        # Get and add powers of 2
        powers_of_2 = get_power_sum(bin_prime)

        # Display
        print(
            f"Your number: {prime}\nIn binary: {bin_prime}\nSum of powers: {powers_of_2}"
        )

    else:
        # Example usage:
        upper_limit = int(input("What is the upper limit of your primes? -> "))
        prime_numbers = get_prime_list(upper_limit)
        ##### print(f"Prime numbers up to {upper_limit}: {prime_numbers}")
        prime_scan(prime_numbers)


if __name__ == "__main__":
    main()
