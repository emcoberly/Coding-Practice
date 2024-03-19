"""
Solution offered by u/StaticMoose on Reddit
Source:
  https://www.reddit.com/r/adventofcode/comments/18luw6q/2023_day_17_a_longform_tutorial_on_day_17/
"""

import os
import sys

# Read the puzzle input
with open(sys.argv[1], "r", encoding="UTF-8") as file:
    file_contents = file.read()
# Trim whitespace on either end
file_contents = file_contents.strip()

# Parse into rows
grid_rows = file_contents.split("\n")

# Parse into numbers
grid = [[int(x) for x in row] for row in grid_rows]

# Calculate size of grid (we assume a square grid)
height = len(grid)
width = len(grid[0])

# Find the ending state
end_x = width - 1
end_y = height - 1

# Initialize data structures
state_queues_by_cost = {}
seen_cost_by_state = {}


def add_state(cost, x, y):
    """
    Adds state to queue
    """

    # Do bounds checking
    if x < 0 or y < 0:
        return
    if x >= width or y >= height:
        return

    # Calculate the cost of stepping on this square
    new_cost = cost + grid[y][x]

    # Did we find the end?
    if x == end_x and y == end_y:
        # Display our cost and early exit!
        print(">>>", new_cost + grid[0][0], "<<<")
        sys.exit(0)

    # Create the state
    state = (x, y)

    # Have we seen this state before?
    if state not in seen_cost_by_state:
        # Save the state to visit later
        state_queues_by_cost.setdefault(new_cost, []).append(state)

        # Mark the state as seen
        seen_cost_by_state[state] = new_cost


def main():
    """
    Main function
    """

    os.system("cls" if os.name == "nt" else "clear")

    # print("\n".join("".join(str(grid[i])) for i in range(height)))

    # Initial state
    add_state(cost=0, x=0, y=0)

    # Iterate till we find the exit
    while True:
        # Find the horizon of our search, the states with the lowest cost
        # All future states will have at least this value, so we can just pop
        # Note: this assumes all grid values are positive!

        # Get lowest cost
        current_cost = min(state_queues_by_cost.keys())

        # Get all states at that cost
        next_states = state_queues_by_cost.pop(current_cost)

        visit_e = 0
        visit_n = 0
        visit_s = 0
        visit_w = 0

        # Process each state
        for state in next_states:
            # Break out the state variables
            (x, y) = state

            # Look north, south, east, and west
            if visit_e < 3:
                add_state(cost=current_cost, x=x + 1, y=y)
                visit_e += 1
            if visit_w < 3:
                add_state(cost=current_cost, x=x - 1, y=y)
                visit_w += 1
            if visit_s < 3:
                add_state(cost=current_cost, x=x, y=y + 1)
                visit_s += 1
            if visit_n < 3:
                add_state(cost=current_cost, x=x, y=y - 1)
                visit_n += 1


if __name__ == "__main__":
    main()
