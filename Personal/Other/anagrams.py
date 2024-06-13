"""
Gets a set of anagrams from a list
"""

import os

# Credit to https://www.geeksforgeeks.org/python-program-for-quicksort/ for the following
#   partition() and quickSort() functions


def partition(array, low, high):
    """ "
    Function to find the partition position
    """

    pivot = array[high]
    i = low - 1
    for j in range(low, high):
        if array[j] <= pivot:
            i = i + 1
            (array[i], array[j]) = (array[j], array[i])
    (array[i + 1], array[high]) = (array[high], array[i + 1])
    return i + 1


def quick_sort(array, low, high):
    """
    Function to perform quicksort
    """

    if low < high:
        pi = partition(array, low, high)
        quick_sort(array, low, pi - 1)
        quick_sort(array, pi + 1, high)


def find_anagrams(dictionary):
    """
    Finds and returns a list of anagram sets
    """

    alphabetized = []
    anagram_dict = {}
    for word in dictionary:
        sorted_word = list(word)
        quick_sort(sorted_word, 0, len(sorted_word) - 1)
        if str(sorted_word) in alphabetized:
            anagram_dict[str(sorted_word)].append(word)
        else:
            anagram_dict[str(sorted_word)] = [word]
            alphabetized.append(str(sorted_word))
    return [
        tuple(sorted(value)) for key, value in anagram_dict.items() if len(value) > 1
    ]


def main():
    """
    Main function
    """

    os.system("cls" if os.name == "nt" else "clear")

    print(
        find_anagrams(
            [
                "tea",
                "ate",
                "eat",
                "beans",
                "banana",
                "stream",
                "master",
                "ocean",
                "canoe",
                "llama",
                "grotesque",
                "canteloupe",
            ]
        )
    )


if __name__ == "__main__":
    main()
