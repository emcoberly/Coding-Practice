"""
This file was written in another file
"""


def hello_world():
    """
    hello_world() docstring
    """
    print("Hello world!")


def introduce_yourself():
    """
    introduce_yourself() docstring
    """
    return input("What is your name? -> ")


def main():
    """
    main() docstring
    """
    hello_world()
    print(f"Hello, {introduce_yourself()}!")
    print("Haha, get it? Because you are my world!")


if __name__ == "__main__":
    main()
