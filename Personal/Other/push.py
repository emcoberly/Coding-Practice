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
        os.chdir("C://Users/mscob/OneDrive/Documents/Coding-Practice/")

    def format(self):
        """
        Perform any necessary formatting
        """
        os.system("black .")

    def git(self):
        """
        Perform Git process
        """
        os.system("git add .")
        os.system(f'git commit -m "{self.message}"')
        os.system("git push")

    def return_cd(self):
        """
        Return to original directory
        """
        os.chdir(self.cd)


def main():
    """
    main() docstring
    """
    # Clear console
    os.system("cls" if os.name == "nt" else "clear")

    # Initialize script with current path
    git = GitScript(os.getcwd())

    # DO NOT FORGET to update file path used in repo() function
    if git.check_for_update() == "y":
        sys.exit(0)

    # Commit message for Git
    git.get_commit_message()

    # cd to Coding-Practice repo
    git.repo()

    # Format files
    git.format()

    # git add, commit, push
    git.git()

    # Return to original directory
    git.return_cd()


if __name__ == "__main__":
    main()
