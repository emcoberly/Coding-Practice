"""
Eddie Coberly
CPTR 454
Homework 8
February 28, 2024
"""

import os

# def iterate(line, broken_list):
#     """
#     Iterate through string
#     """
#     possibilities = 0

#     if len(broken_list) == 0:
#         if '#' not in line:
#             return 1
#         return 0
#     for i in range(broken_list[0]):
#         if '.' not in line[i:i + broken_list[0]]:
#             possibilities += 1
#         possibilities += iterate(line[broken_list[0] + 1:], broken_list[1:])
#     return possibilities


def iterate(line, broken_list):
    """
    Iterate through string
    """
    possibilities = 0
    pass_list = broken_list[1:] if broken_list[0] == 0 else broken_list
    pass_line = line[:]
    if line == "":
        if pass_list == []:
            return 1
        return 0
    if pass_list == []:
        return 0
    if line[0] == ".":
        possibilities += iterate(pass_line[1:], pass_list)
    elif line[0] == "#":
        pass_list[0] -= 1
        possibilities += iterate(pass_line[1:], pass_list)
    else:
        pass_line = "." + pass_line[1:]
        possibilities += iterate(pass_line, pass_list)
        pass_line = "#" + pass_line[1:]
        possibilities += iterate(pass_line, pass_list)
    return possibilities


def main():
    """
    Main function
    """
    possibilities = 0

    os.system("cls" if os.name == "nt" else "clear")

    # signals_count = []
    signals = []
    broken_count = []
    with open("input.txt", "r", encoding="UTF-8") as f:
        lines = f.readlines()
        # signals_count = [
        #     [len(item) for item in line.split()[0].split(".") if item != ""]
        #     for line in lines
        # ]
        signals = [line.split()[0] for line in lines]
        broken_count = [
            [int(item) for item in line.split()[1].split(",")] for line in lines
        ]

    for index, line in enumerate(signals):
        possibilities += iterate(line, broken_count[index])
    print(possibilities)


if __name__ == "__main__":
    main()
