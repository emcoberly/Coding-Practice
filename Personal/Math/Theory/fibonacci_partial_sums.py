"""
This file computes different properties of the Fibonacci sequence
"""
import os


def get_partial_sum_size(sequence):
    """
    Get size of partial sum to be used for other functions
    """

    while True:
        try:
            size = int(input("What is the size of the partial sum? -> "))
            if size < 1 or size > len(sequence):
                print(
                    "Partial sum size must be >= 1 and <= list size. Please try again."
                )
                continue
            break
        except ValueError:
            print("You are only allowed to enter integer inputs. Please try again.")

    return size


def get_partial_sum(sequence, size):
    """
    Gathers a partial sum from a sequence *sequence*
    """
    return sum(sequence[:size])


def get_n_partial_sums(sequence, size):
    """
    Calculate n partial sums of a sequence of a fixed size
    """

    while True:
        try:
            n_sums = int(
                input(f"How many sums of size {size} would you like to calculate? -> ")
            )
            if n_sums + size > len(sequence) + 1:
                print(
                    "You will exceed the current sequence's bounds. Please enter a smaller number."
                )
                continue
            break
        except ValueError:
            print("You are only allowed to enter integer inputs. Please try again.")

    sums_list = []
    for i in range(n_sums):
        sums_list.append(get_partial_sum(sequence[i:], size))
    return sums_list


def view_sequence(sequence):
    """
    Prints the sequence
    """

    print(f"Your sequence is:\n{sequence}")


def main():
    """
    Main function
    Creates menu and allows user to perform operations
    """

    option = ""
    sequence = []

    os.system("cls" if os.name == "nt" else "clear")
    print(
        "Welcome to the Fibonacci analyzer! You may perform any of the following functions by\
 entering the letter shown"
    )
    print(
        "Note that you must generate a Fibonacci sequence before you can perform any of the other\
 functions."
    )

    while option != "q":
        print()
        print("What would you like to do?")
        print("- (G)enerate a new Fibonacci sequence")
        print("- (P)artial sum")
        print("- (C)alculate n partial sums")
        print("- (Q)uit")
        print()
        option = input("-> ").lower()
        os.system("cls" if os.name == "nt" else "clear")
        if not option in ["g", "p", "c", "q"]:
            print()
            print(
                "You must enter an input specified in the above list. Please try again."
            )
            continue
        if option not in ["g", "q"] and len(sequence) == 0:
            print("Please generate a sequence before calling this operation.")
            continue
        if option == "q":
            exit(0)
        if option == "g":
            with open(
                "../GeneralUseFunctions/fibonacci.txt", "r", encoding="UTF-8"
            ) as f:
                lines = f.readlines()
                sequence = [int(line.strip()) for line in lines]
        elif option == "p":
            size = get_partial_sum_size(sequence)
            partial_sum = get_partial_sum(sequence, size)
            print(f"\nYour partial sum is: {partial_sum}")
            print(f"This is the sum of {sequence[:size]}\n")
        elif option == "c":
            size = get_partial_sum_size(sequence)
            partial_sums = get_n_partial_sums(sequence, size)
            print(f"\nYour partial sums are: {partial_sums}\n")
        view_sequence(sequence)


if __name__ == "__main__":
    main()
