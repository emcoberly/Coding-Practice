"""
Finding path for crucible
"""

import sys

ARRAY_WIDTH = 13
ARRAY_HEIGHT = 13
heat_loss = []


class Block:
    """
    For each city block
    """

    def __init__(self, coordinate, value):
        self.coordinate = coordinate
        self.value = value

    def __str__(self):
        return f"Block {(self.coordinate)} has a value of {self.value}."


def check_adjacent(left, right, up, down, row, col, checked, heat_list, heat_grid):
    """
    Checks adjacent city blocks
    """

    if len(checked) == 1000:
        checked.pop()
        heat_list.pop()
        return
    if row == 12 and col == 12:
        heat_loss.append(sum(heat_list))
        checked.pop()
        heat_list.pop()
        return
    if (row, col) in checked:
        checked.pop()
        heat_list.pop()
        return

    checked.append((row, col))
    heat_list.append(heat_grid[row][col])

    if up < 3 and row - 1 > 0:
        print(
            f"checked={checked}\nheat_list={heat_list}\nrow={row}\ncol={col}\nup={up}\nleft={left}\ndown={down}\nright{right}\n"
        )
        check_adjacent(0, 0, up + 1, 0, row - 1, col, checked, heat_list, heat_grid)
    if left < 3 and col - 1 > 0:
        print(
            f"checked={checked}\nheat_list={heat_list}\nrow={row}\ncol={col}\nup={up}\nleft={left}\ndown={down}\nright{right}\n"
        )
        check_adjacent(left + 1, 0, 0, 0, row, col - 1, checked, heat_list, heat_grid)
        exit(0)
    if down < 3 and row + 1 < ARRAY_HEIGHT - 1:
        print(
            f"checked={checked}\nheat_list={heat_list}\nrow={row}\ncol={col}\nup={up}\nleft={left}\ndown={down}\nright{right}\n"
        )
        check_adjacent(0, 0, 0, down + 1, row + 1, col, checked, heat_list, heat_grid)
    if right < 3 and col + 1 < ARRAY_WIDTH - 1:
        print(
            f"checked={checked}\nheat_list={heat_list}\nrow={row}\ncol={col}\nup={up}\nleft={left}\ndown={down}\nright{right}\n"
        )
        check_adjacent(0, right + 1, 0, 0, row, col + 1, checked, heat_list, heat_grid)


def main():
    """
    Main function
    """

    my_array = [[0] * ARRAY_WIDTH] * ARRAY_HEIGHT
    row = 0
    string_list = []
    with open(sys.argv[1], "r", encoding="utf-8") as f:
        string_list = f.readlines()

    for row in range(len(string_list)):
        my_array[row] = [int(string_list[row][col]) for col in range(len(string_list))]

    block_list = []
    for row in range(len(my_array)):
        for col in range(len(my_array[row])):
            block_list.append(Block((row, col), my_array[row][col]))

    check_adjacent(0, 0, 0, 0, 0, 0, [], [], my_array)
    # print(min(heat_loss))


if __name__ == "__main__":
    main()
