"""
User can decide how many points to plot
"""

import proper_divisors as pd
import matplotlib.pyplot as plt


def main():
    """
    Main function
    """

    while True:
        try:
            points_count = int(input("How many amicables would you like to plot? -> "))
            break
        except ValueError:
            print("Please enter a positive integer.")

    points = [
        (i, pd.s(i))
        for i in range(1, points_count)
        if i != pd.s(i) and pd.s(i) <= points_count
    ]
    abundants = [(i, pd.s(i)) for i in range(1, points_count) if pd.s(i) > points_count]
    perfects = [(i, pd.s(i)) for i in range(1, points_count) if i == pd.s(i)]

    plt.scatter(
        [point[0] for point in points], [point[1] for point in points], color="k", s=10
    )
    plt.scatter(
        [abundant[0] for abundant in abundants],
        [abundant[1] for abundant in abundants],
        color="r",
        s=150,
        marker="X",
    )
    plt.scatter(
        [perfect[0] for perfect in perfects],
        [perfect[1] for perfect in perfects],
        color="y",
        s=150,
        marker="*",
    )

    red = 0
    green = 0
    blue = 1
    for index, point in enumerate(points[1:]):
        plt.plot(
            [point[0], pd.s(point[0])],
            [point[1], pd.s(point[1])],
            linestyle="solid",
            linewidth=0.7,
            color=(red, green, blue),
        )
        if index < points_count / 3:
            blue -= 2.9 / points_count
            red += 2.9 / points_count
        elif index < points_count / 1.5:
            red -= 2.9 / points_count
            green += 2.9 / points_count
        else:
            green -= 2.9 / points_count
            blue += 2.9 / points_count

    plt.savefig("amicables.png", format="PNG")
    plt.clf()


if __name__ == "__main__":
    main()
