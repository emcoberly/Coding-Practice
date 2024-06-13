"""
Can I create an executable Python file?
"""

import os


def docstring(message, sof=False):
    """
    Generates docstring for file and functions
    """
    tab = "\t" * (not sof)
    return "{}'''\n{}{}\n{}'''\n".format(tab, tab, message, tab)


def main():
    """
    Create a new Python file
    """

    with open("hello_world.py", "w", encoding="UTF-8") as _f:
        _f.write(
            docstring("This file was written in another file", True)
            + "def hello_world():\n"
            + docstring("hello_world() docstring")
            + '\tprint("Hello world!")\n'
            "def introduce_yourself():\n"
            + docstring("introduce_yourself() docstring")
            + "\treturn input('What is your name? -> ')\n"
            "def main():\n" + docstring("main() docstring") + "\thello_world()\n"
            "\tprint(f'Hello, {introduce_yourself()}!')\n"
            "\tprint('Haha, get it? Because you are my world!')\n"
            'if __name__ == "__main__":\n'
            "\tmain()\n"
        )
    os.system("black hello_world.py")
    os.system("cls" if os.name == "nt" else "clear")
    os.system("python3 hello_world.py")


if __name__ == "__main__":
    main()
