"""
More fun with amicables
"""

import proper_divisors


def main():
    """
    Docstring
    """
    for _ in range(9):
        div_sum = sum(proper_divisors.get_proper_divisors(div_sum))
        print(div_sum)


if __name__ == "__main__":
    main()
