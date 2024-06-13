"""
Generate a Fibonacci sequence
"""

import get_integer
import os


def fibonacci_terms(terms):
    """
    Generates a list of *terms* Fibonacci numbers
    """

    fibonacci_list = [1, 1]
    if terms == 1:
        return [1]
    if terms == 2:
        return fibonacci_list
    for i in range(2, terms):
        fibonacci_list.append(fibonacci_list[i - 1] + fibonacci_list[i - 2])
    return fibonacci_list


def main():
    """
    Main function
    Creates a file with n Fibonacci numbers
    """

    user_input = get_integer.get_integer()
    generated_list = fibonacci_terms(user_input)

    with open("fibonacci.txt", "w", encoding="UTF-8") as f:
        for i in generated_list:
            f.write(str(i) + "\n")

    os.system("cls" if os.name == "nt" else "clear")


if __name__ == "__main__":
    main()
