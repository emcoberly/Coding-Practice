"""
Search for amicable numbers
"""

from Personal.Math.GeneralUseFunctions import proper_divisors


def main():
    """
    Main function
    """
    # for num in range(1,301):
    #     print(f"Divisors sum of {num}:\t{sum(get_proper_divisors(num))}")

    num_sum_pairs = [
        (num, sum(proper_divisors.get_proper_divisors(num))) for num in range(1, 20001)
    ]
    # print(num_sum_pairs)

    amicables = []
    perfects = []
    for num1 in num_sum_pairs:
        if num1[0] == num1[1]:
            perfects.append(num1[0])
        for num2 in num_sum_pairs:
            if num1[0] == num2[1] and num1[1] == num2[0] and num1 != num2:
                if (num1[1], num1[0]) in amicables:
                    continue
                amicables.append(num1)

    print(f"Amicables:\t{amicables}")
    print(f"Perfects:\t{perfects}")


if __name__ == "__main__":
    main()
