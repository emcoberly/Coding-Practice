"""
Push script in Python
"""

import os
import sys


class GitScript:
    """
    Git script class
    """

    def __init__(self, cd):
        self.message = ""
        self.cd = cd

    def check_for_update(self):
        """
        Check that this file won't go to the wrong place
        """
        return input("Do you need to update any file paths in this script? (y/n) ")

    def get_commit_message(self):
        """
        Input commit message
        """
        self.message = input("Enter a commit message:\n")

    def repo(self):
        """
        Change to repo directory and format all files
        """
        os.system("cd ~/OneDrive/Documents/Coding-Practice/")
        os.system("black .")

    def git(self):
        """
        Perform Git process
        """
        os.system("git add .")
        os.system(f'git commit -m "{self.message}"')
        os.system("git push")

    def return_cd(self):
        os.system(f"cd {self.cd}")


def main():
    """
    main() docstring
    """
    # Clear console
    os.system("cls" if os.name == "nt" else "clear")

    git = GitScript(os.getcwd())

    if git.check_for_update() == "y":
        sys.exit(0)

    git.get_commit_message()
    git.repo()
    git.git()
    git.return_cd()


if __name__ == "__main__":
    main()
