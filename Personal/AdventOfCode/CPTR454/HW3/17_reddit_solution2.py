"""
Solution offered by u/atrocia6 on Reddit
Source: https://github.com/tmo1/adventofcode/blob/main/2023/17.py
"""
# DOC STRING WITH CREDIT IS MY DOING
# ALL COMMENTS ARE MY OWN UNLESS OTHERWISE STATED

import itertools
import sys  # COMMAND LINE FILE INPUT
from heapq import heappop, heappush
from collections import defaultdict

# ONLY THE FOLLOWING COMMENTS ARE FROM THE CREATOR; ALL OTHER COMMENTS ARE MY OWN
# https://docs.python.org/3/library/heapq.html#priority-queue-implementation-notes
pq = []  # list of entries arranged in a heap
entry_finder = {}  # mapping of tasks to entries
REMOVED = "<removed-task>"  # placeholder for a removed task
counter = itertools.count()  # unique sequence count


def add_task(task, priority=0):
    """
    DOCSTRING IN PLACE OF A COMMENT
    Adds a block to the priority queue with a priority defaulted to 0
    It looks like "count" is only used for tracking time complexity or number of comparisons
    Every entry of the PQ consists of a priority, count, and block (task) to visit
    This function pushes the block onto the queue unless it has been removed from the queue,
        in which case it is removed
    """

    if task in entry_finder:
        remove_task(task)
    count = next(counter)
    entry = [priority, count, task]
    entry_finder[task] = entry
    heappush(pq, entry)


def remove_task(task):
    """
    DOCSTRING IN PLACE OF A COMMENT
    Removes a block to explore and sets new_consecutive to REMOVED flag
    """

    entry = entry_finder.pop(task)
    entry[-1] = REMOVED


def pop_task():
    """
    DOCSTRING IN PLACE OF A COMMENT
    Removes a block from the queue and returns it, but only if the block has not been removed
    I believe this is intended to not backtrack to a block (inefficient)
    """

    while pq:
        priority, count, task = heappop(pq)
        if task is not REMOVED:
            del entry_finder[task]
            return task
    raise KeyError("pop from an empty priority queue")


# CONVERT DATA TO GRID FROM COMMAND LINE
heat_map = [
    [int(n) for n in line.strip()] for line in open(sys.argv[1], "r", encoding="UTF-8")
]
# DEFINE POSSIBLE MOVEMENTS FROM CURRENT BLOCK: N, E, S, W
movement = {0: (0, -1), 1: (1, 0), 2: (0, 1), 3: (-1, 0)}

# THE FOLLOWING "for" LOOPS CHECK EACH BLOCK AND ADD THE 10 BLOCKS N,E,S,W OF IT
for y in range(len(heat_map)):
    for x in range(len(heat_map[0])):
        for direction in range(4):
            # for consecutive in range(1, 4):   # USED FOR SOLUTION 1
            for consecutive in range(1, 11):
                add_task((x, y, direction, consecutive), 1000000)

# INITIALIZE STARTING BLOCK (x=0, y=0, directions=E/S, consecutive=0)
add_task((0, 0, 1, 0))
add_task((0, 0, 2, 0))  # ADDED FOR SOLUTION 2

total_heat = defaultdict(lambda: 1000000)
# total_heat[(0, 0, 1, 0)] = 0              # USED BY ITSELF FOR SOLUTION 1
total_heat[(0, 0, 1, 0)], total_heat[(0, 0, 2, 0)] = 0, 0

# ITERATE UNTIL END IS REACHED, WHICH IS WHERE "quit()" HAPPENS
while True:
    t = pop_task()
    x, y, direction, consecutive = t

    # LAST "and" IN THE FOLLOWING USED ONLY FOR SOLUTION 2
    # QUITS IF THE END IS REACHED, BUT ONLY IF >= 4 BLOCKS WERE TRAVELED TO REACH IT
    if x == len(heat_map[0]) - 1 and y == len(heat_map) - 1 and consecutive >= 4:
        print(total_heat[t])  # PRINTS THE TOTAL HEAT AT THE FINISHING BLOCK
        quit()

    # THE FOLLOWING IS USED FOR SOLUTION 1
    # neighbors = [((direction + 1) % 4, 1), ((direction - 1) % 4, 1)]
    # if consecutive < 3:
    #     neighbors.append((direction, consecutive + 1))

    # THE NEXT 5 LINES HAVE BEEN MODIFIED TO SOLVE SOLUTION 2
    neighbors = []
    if consecutive >= 4:
        neighbors = [((direction + 1) % 4, 1), ((direction - 1) % 4, 1)]
    if consecutive < 10:
        neighbors.append((direction, consecutive + 1))
    # THE ABOVE KEEPS TRACK OF WHERE TO TRAVEL FROM CURRENT BLOCK
    # "neighbors" IS FOR VALID BLOCKS TO VISIT
    # FIRST "if" LETS THE CRUCIBLE TURN AFTER 4 BLOCKS
    # SECOND "if" KEEPS THE CRUCIBLE FROM TRAVELING BEYOND 10 BLOCKS

    # ITERATE THROUGH EACH NEIGHBORING BLOCK
    for neighbor in neighbors:
        new_direction, new_consecutive = neighbor
        new_x, new_y = x + movement[new_direction][0], y + movement[new_direction][1]
        new_t = (new_x, new_y, new_direction, new_consecutive)
        if 0 <= new_x < len(heat_map[0]) and 0 <= new_y < len(heat_map):
            new_heat = total_heat[t] + heat_map[new_y][new_x]
            if new_heat < total_heat[new_t]:
                # FOLLOW PATH OF LEAST HEAT, PRIORITIZE THIS PATH
                total_heat[new_t] = new_heat
                add_task(new_t, new_heat)
