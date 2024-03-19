"""
Advent of Code - Day 12 Solution
Credit to https://www.youtube.com/watch?v=g3Ms5e7Jdqo
"""

# ALL COMMENTS ARE MINE AND DESCRIBE WHAT THE ALGORITHM IS DOING
# MY CODE FOR THIS WORKS VERY SIMILARLY, BUT i WAS HAVING SOME TROUBLE WITH THE SEMANTICS

import sys

# PART 2 CACHE
cache = {}


def count(cfg, nums):
    """
    Count remaining string possibilities
    cfg = remaining string to be analyzed
    nums = remaining number of configurations to be analyzed
    """

    # IF REMAINING STRING IS EMPTY:
    #     RETURN 1 IF ALL NUMBERS HAVE BEEN USED
    #     ELSE, WE DIDN'T COUNT AT LEAST ONE SEQUENCE, SO RETURN 0
    if cfg == "":
        return 1 if nums == () else 0

    # IF WE HAVE LOOKED AT ALL THE NUMBERS IN THE ARRAY:
    #     IF ANY #'S REMAIN, RETURN 0
    #     ELSE, WE'VE COUNTED EVERYTHING, SO RETURN 1
    if nums == ():
        return 0 if "#" in cfg else 1

    # FOR PART 2 CACHING
    # REMEMBER THE VALUE FOR A PARTICULAR STRING AND CACHE IT
    key = (cfg, nums)
    if key in cache:
        return cache[key]

    # INITIALIZE RETURN VARIABLE
    result = 0

    # CASE 1: STRING STARTS WITH A '.'
    #     GET COUNT FROM REMAINING STRING
    if cfg[0] in ".?":
        result += count(cfg[1:], nums)

    # CASE 2:
    #     - MAKE SURE THE FIRST LIST ITEM CAN STILL BE PLACED IN cfg
    #     - MAKE SURE THERE IS NO DOT IN THE SECTION IN WHICH WE ARE PLACING OUR NUM
    #     - MUST HAVE EITHER REMAINDER OF STRING AS LAST NUMBER OR
    #       WE ARE NOT ADDING #'S NEXT TO PREVIOUSLY CHECKED #'S
    if cfg[0] in "#?":
        if (
            nums[0] <= len(cfg)
            and "." not in cfg[: nums[0]]
            and (nums[0] == len(cfg) or cfg[nums[0]] != "#")
        ):
            # SKIP STRING OF #'S + 1 (AS IF FOLLOWED BY A '.')
            # WE HAVE CHECKED nums[0], SO PASS REMAINING NUMBERS
            result += count(cfg[nums[0] + 1 :], nums[1:])

    # FOR PART 2 CACHING
    cache[key] = result

    return result


def main():
    """
    Main function
    """

    total = 0
    for line in open(sys.argv[1], "r", encoding="UTF-8"):
        cfg, nums = line.split()
        nums = tuple(map(int, nums.split(",")))

        # MODIFY INPUT FOR PART 2
        cfg = "?".join([cfg] * 5)
        nums *= 5

        total += count(cfg, nums)
    print(f"Total: {total}")


if __name__ == "__main__":
    main()

# MY FAILED CODE, FOR COMPARISON

# def iterate(line, broken_list):
#     """
#     Iterate through string
#     """
#     possibilities = 0
#     pass_list = broken_list[1:] if broken_list[0] == 0 else broken_list
#     pass_line = line[:]
#     if line == "":
#         if pass_list == []:
#             return 1
#         return 0
#     if pass_list == []:
#         return 0
#     if line[0] == ".":
#         possibilities += iterate(pass_line[1:], pass_list)
#     elif line[0] == "#":
#         pass_list[0] -= 1
#         possibilities += iterate(pass_line[1:], pass_list)
#     else:
#         pass_line = "." + pass_line[1:]
#         possibilities += iterate(pass_line, pass_list)
#         pass_line = "#" + pass_line[1:]
#         possibilities += iterate(pass_line, pass_list)
#     return possibilities


# def main():
#     """
#     Main function
#     """
#     possibilities = 0

#     os.system("cls" if os.name == "nt" else "clear")

#     # signals_count = []
#     signals = []
#     broken_count = []
#     with open("input.txt", "r", encoding="UTF-8") as f:
#         lines = f.readlines()
#         # signals_count = [
#         #     [len(item) for item in line.split()[0].split(".") if item != ""]
#         #     for line in lines
#         # ]
#         signals = [line.split()[0] for line in lines]
#         broken_count = [
#             [int(item) for item in line.split()[1].split(",")] for line in lines
#         ]

#     for index, line in enumerate(signals):
#         possibilities += iterate(line, broken_count[index])
#     print(possibilities)
