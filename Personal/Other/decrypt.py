"""
Docstring to appease pylint
"""
my_string = input("Enter a string: ")
for i in range(26):
    for letter in my_string:
        if letter.isalpha():
            if ord(letter) + i > 122:
                print(chr(ord(letter) + i - 26), end="")
            else:
                print(chr(ord(letter) + i), end="")
        else:
            print(letter, end="")
    print()
