"""
Forces user to enter integer input
"""


def get_integer():
    """
    Checks if user input is an integer
    """

    while True:
        try:
            user_input = int(input("Please enter an integer -> "))
            return user_input
        except ValueError:
            print("Invalid input. Please try again.")
