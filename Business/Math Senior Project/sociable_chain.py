"""
Print an image of a sociable chain of numbers
"""

import proper_divisors as pd
import matplotlib.pyplot as plot

PERFECTS = [0, 6, 28, 496, 8128]


def main():
    """
    Main function
    """

    while True:
        try:
            number = int(input("Enter an integer to create a sociable chain. -> "))
            file_ext = int(number)
            break
        except ValueError:
            print("Please enter an integer.")
            
    numbers = [7, 24, 25, 30, 34, 138, 216, 276]

    for number in numbers:
      file_ext = int(number)
      while pd.s(number) != 0 and number not in PERFECTS and number < 35000:
        plot.scatter([number], [pd.s(number)], color="k", s=25)
        plot.plot(
          [number, pd.s(number)],
					[pd.s(number), pd.s(pd.s(number))],
					color="b",
					linewidth=0.7,
					linestyle="solid",
				)
        number = pd.s(number)
      marker = "*" if pd.s(number) in PERFECTS else "."
      color = "y" if pd.s(number) in PERFECTS else "k"
      plot.scatter([number], [pd.s(number)], color=color, s=75, marker=marker)
      plot.savefig(f"sociable_chain_{file_ext}.png", format="PNG")
      plot.clf()
    plot.plot([220, 284], [284, 220], color='k', linewidth=2.0, linestyle="solid")
    plot.scatter([220, 284], [284, 220], color="r", marker="*", s=250)
    plot.gca().set_xlim([200, 300])
    plot.gca().set_ylim([200, 300])
    plot.savefig("amicable_pair.png", format="PNG")
    plot.clf()


if __name__ == "__main__":
    main()
