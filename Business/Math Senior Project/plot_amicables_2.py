"""
Plot amicable numbers map
"""

import matplotlib.pyplot as plt

POINTS = [
    (1, 0),
    (2, 1),
    (3, 1),
    (4, 3),
    (5, 1),
    (6, 6),
    (7, 1),
    (8, 7),
    (9, 4),
    (10, 8),
    (11, 1),
    (12, 16),
    (13, 1),
    (14, 10),
    (15, 9),
    (16, 15),
    (17, 1),
    (18, 21),
    (19, 1),
    (20, 22),
    (21, 11),
    (22, 14),
    (23, 1),
    (25, 6),
    (26, 16),
    (27, 13),
    (28, 28),
]


def plot_dots():
    """
    Map amicables indirectly
    """

    x_vals = [point[0] for point in POINTS]
    y_vals = [point[1] for point in POINTS]
    plt.scatter(x_vals, y_vals, color="k")

    # PLOT PRIMES
    plt.plot([[2, 2], [2, 1]], [[1, 0], [0, 0]], linestyle="dotted", color="r")
    plt.plot([[3, 3], [3, 1]], [[1, 0], [0, 0]], linestyle="dotted", color="r")
    plt.plot([[5, 5], [5, 1]], [[1, 0], [0, 0]], linestyle="dotted", color="r")
    plt.plot([[7, 7], [7, 1]], [[1, 0], [0, 0]], linestyle="dotted", color="r")
    plt.plot([[11, 11], [11, 1]], [[1, 0], [0, 0]], linestyle="dotted", color="r")
    plt.plot([[13, 13], [13, 1]], [[1, 0], [0, 0]], linestyle="dotted", color="r")
    plt.plot([[17, 17], [17, 1]], [[1, 0], [0, 0]], linestyle="dotted", color="r")
    plt.plot([[19, 19], [19, 1]], [[1, 0], [0, 0]], linestyle="dotted", color="r")
    plt.plot([[23, 23], [23, 1]], [[1, 0], [0, 0]], linestyle="dotted", color="r")

    # PLOT NEXT OUT FROM PRIMES
    plt.plot([[4, 4], [4, 3]], [[3, 1], [1, 1]], linestyle="dotted", color="g")
    plt.plot([[8, 8], [8, 7]], [[7, 1], [1, 1]], linestyle="dotted", color="g")
    plt.plot([[21, 21], [21, 11]], [[11, 1], [1, 1]], linestyle="dotted", color="g")
    plt.plot([[25, 25], [25, 6]], [[6, 1], [1, 1]], linestyle="dotted", color="g")

    # NEXT LAYER
    plt.plot([[9, 9], [9, 4]], [[4, 1], [1, 1]], linestyle="dotted", color="b")
    plt.plot([[10, 10], [10, 8]], [[8, 7], [7, 7]], linestyle="dotted", color="b")

    # EVEN MORE NEXT LAYER
    plt.plot([[14, 14], [14, 10]], [[10, 8], [8, 8]], linestyle="dotted", color="y")
    plt.plot([[15, 15], [15, 9]], [[9, 4], [4, 4]], linestyle="dotted", color="y")

    # LAST OF DEFICIENTS
    plt.plot([[16, 16], [16, 15]], [[15, 9], [9, 9]], linestyle="dotted", color="m")
    plt.plot([[22, 22], [22, 14]], [[14, 10], [10, 10]], linestyle="dotted", color="m")

    # ABUNDANTS LESS 24
    plt.plot([[12, 16], [16, 16]], [[16, 16], [16, 15]], linestyle="dotted", color="c")
    plt.plot([[18, 21], [21, 21]], [[21, 21], [21, 11]], linestyle="dotted", color="c")
    plt.plot([[20, 22], [22, 22]], [[22, 22], [22, 14]], linestyle="dotted", color="c")

    plt.savefig("amicable_graph.png", format="PNG")
    plt.clf()


def plot_lines():
    """
    Map amicables directly
    """

    x_vals = [point[0] for point in POINTS]
    y_vals = [point[1] for point in POINTS]
    plt.scatter(x_vals, y_vals, color="k", s=20)

    # PLOT PRIMES IN RED
    plt.plot([2, 1], [1, 0], linestyle="solid", color="r")
    plt.plot([5, 1], [1, 0], linestyle="solid", color="r")
    plt.plot([17, 1], [1, 0], linestyle="solid", color="r")
    plt.plot([23, 1], [1, 0], linestyle="solid", color="r")

    plt.plot([[27, 13], [13, 1]], [[13, 1], [1, 0]], linestyle="solid", color="y")
    plt.plot(
        [[12, 16], [16, 15], [15, 9], [9, 4], [4, 3], [3, 1]],
        [[16, 15], [15, 9], [9, 4], [4, 3], [3, 1], [1, 0]],
        linestyle="solid",
        color="m",
    )
    plt.plot(
        [[18, 21], [21, 11], [11, 1]],
        [[21, 11], [11, 1], [1, 0]],
        linestyle="solid",
        color="b",
    )
    plt.plot(
        [[20, 22], [22, 14], [14, 10], [10, 8], [8, 7], [7, 1]],
        [[22, 14], [14, 10], [10, 8], [8, 7], [7, 1], [1, 0]],
        linestyle="solid",
        color="c",
    )
    plt.plot([25, 6], [6, 6], linestyle="solid", color="g")
    plt.plot([26, 16], [16, 15], linestyle="solid", color="m")
    plt.scatter([28, 6], [28, 6], color="k", s=150, marker="*")

    plt.text(3.5, 6, "(6,6)")
    plt.text(24.5, 28, "(28,28)")

    plt.xlabel("n")
    plt.ylabel("s(n)")
    plt.margins(x=0.03, y=0.05)
    plt.grid(color="gray", which="both", linestyle="--", linewidth=0.25)

    plt.savefig("amicable_graph2.png", format="PNG", pad_inches="0.1")
    plt.clf()


def main():
    """
    Main function
    """

    plot_dots()
    plot_lines()


if __name__ == "__main__":
    main()
