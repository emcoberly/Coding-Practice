"""
Can I create an executable Python file?
"""

import os


def main():
    """
    Create a new Python file
    """

    with open("hello_world.py", "w", encoding="UTF-8") as _f:
        _f.write(
            "'''\n"
            "This file was written in another file\n"
            "'''\n"
            "def hello_world():\n"
            "\t'''\n\thello_world() docstring\n\t'''\n"
            '\tprint("Hello world!")\n'
            "def introduce_yourself():\n"
            "\t'''\n\tintroduce_yourself() docstring\n\t'''\n"
            "\treturn input('What is your name? -> ')\n"
            "def main():\n"
            "\t'''\n\tmain() docstring\n\t'''\n"
            "\thello_world()\n"
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
