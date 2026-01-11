"""
The Staff class contains necessary attributes for giving him/her a day off.
"""


class Staff:
    """
    Creates a Staff object to be given a day off.
    """

    def __init__(self, data):
        self.name = data[0]
        self.day_1 = data[1]
        self.day_2 = data[2]
        self.friend_1 = data[3]
        self.friend_2 = data[4][: len(data[4]) - 1]
        self.happiness = 0
        self.day_off = ""

    def __str__(self):
        return f"My name is {self.name}. I prefer my days off to be {self.day_1} and {self.day_2}. I prefer to share days off with {self.friend_1} and {self.friend_2}."

    def add_happiness(self, value):
        """
        Increases happiness based on having a preferred day off and with
        preferred people.
        """

        self.happiness += value

    def set_day_off(self, day):
        """
        Sets the day off for the Staff object.
        """

        self.day_off = day
