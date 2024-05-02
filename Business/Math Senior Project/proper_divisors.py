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


def sigma(number):
    return sum(get_proper_divisors(number)) + number


def s(number):
    return sum(get_proper_divisors(number))


def main():
    """
    Main function
    """
    while True:
        try:
            number = int(input("Enter a number: "))
            print(f"s({number}):\t\t\t{s(number)}")
            print(f"σ({number}):\t\t\t{sigma(number)}")
            print(f"Proper divisors:\t{get_proper_divisors(number)}")
            break
        except ValueError:
            print("You must enter an integer.")


if __name__ == "__main__":
    main()
