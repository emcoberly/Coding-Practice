"""
Shows minimum knight moves from particular square
"""

import os
import numpy as np


def initialize_board():
    """
    Initialize 2D array of gameboard
    """
    return np.array([["o"] * 8] * 8)


def print_gameboard(gameboard):
    """
    Prints the gameboard
    """
    for row in gameboard:
        for col in row:
            print(col, end=" ")
        print()


def select_knight():
    """
    Returns position of knight
    """

    print("Please use proper chess notation to answer the following.")
    while True:
        coords = input("Where would you like to place the knight? -> ")

        valid_length = len(coords) == 2
        valid_letter = ord(coords[0]) in range(65, 73) or ord(coords[0]) in range(
            97, 105
        )
        valid_number = ord(coords[-1]) in range(49, 57)
        valid_coords = valid_length and valid_letter and valid_number

        if valid_coords:
            return (ord(coords[0]) % 8 - 1, 8 - int(coords[1]))

        os.system("cls" if os.name == "nt" else "clear")
        if not valid_length:
            print(
                "ERROR:\tYour entry did not meet length requirements. Coordinates should have length: 2"
            )
        if not valid_letter:
            print(
                "ERROR:\tYour entry did not meet letter requirements. Letters should be in range: A–H or a–h"
            )
        if not valid_number:
            print(
                "ERROR:\tYour entry did not meet number requirements. Numbers should be in range: 1–8"
            )

        print()
        print("Proper chess notation is letter + number, e.g., 'c1'. Please try again.")
        print()


def main():
    """
    Main function
    """
    gameboard = initialize_board()
    os.system("cls" if os.name == "nt" else "clear")
    knight_pos = select_knight()
    gameboard[knight_pos[1], knight_pos[0]] = "K"
    print_gameboard(gameboard)


if __name__ == "__main__":
    main()
