"""
The Calendar object is a table exported to CSV as a visual representation
of the day-off calendar created for staff members.
"""

import sys


class Calendar:
    """
    The Calendar object contains an array for each day of the week,
    as well as the fullest day.
    """

    def __init__(self):
        self.monday = ["Monday"]
        self.tuesday = ["Tuesday"]
        self.wednesday = ["Wednesday"]
        self.thursday = ["Thursday"]
        self.friday = ["Friday"]
        self.fullest_day = ""

    def assign_day_off(self, staff, day):
        """
        Assigns a day off to a staff member and adjusts happiness accordingly.
        """

        match day:
            case "Monday":
                self.monday.append(staff.name)
                if staff.friend_1 in self.monday:
                    staff.add_happiness(2)
                if staff.friend_2 in self.monday:
                    staff.add_happiness(1)
            case "Tuesday":
                self.tuesday.append(staff.name)
                if staff.friend_1 in self.tuesday:
                    staff.add_happiness(2)
                if staff.friend_2 in self.tuesday:
                    staff.add_happiness(1)
            case "Wednesday":
                self.wednesday.append(staff.name)
                if staff.friend_1 in self.wednesday:
                    staff.add_happiness(2)
                if staff.friend_2 in self.wednesday:
                    staff.add_happiness(1)
            case "Thursday":
                self.thursday.append(staff.name)
                if staff.friend_1 in self.thursday:
                    staff.add_happiness(2)
                if staff.friend_2 in self.thursday:
                    staff.add_happiness(1)
            case "Friday":
                self.friday.append(staff.name)
                if staff.friend_1 in self.friday:
                    staff.add_happiness(2)
                if staff.friend_2 in self.friday:
                    staff.add_happiness(1)
            case _:
                sys.exit()
        if day == staff.day_1:
            staff.add_happiness(2)
        elif day == staff.day_2:
            staff.add_happiness(1)

    def get_fullest_day(self):
        """
        Determines the fullest day of the week.
        """

        fullest_day = self.monday
        if len(self.tuesday) > len(fullest_day):
            fullest_day = self.tuesday
        if len(self.wednesday) > len(fullest_day):
            fullest_day = self.wednesday
        if len(self.thursday) > len(fullest_day):
            fullest_day = self.thursday
        if len(self.friday) > len(fullest_day):
            fullest_day = self.friday
        return fullest_day

    def export(self, file_name):
        """
        Exports the table to a CSV file.
        """

        lines = []
        for i, level in enumerate(self.get_fullest_day()):
            line = ""
            try:
                line += f"{self.monday[i]},"
            except:
                # Exception(ValueError)
                line += ","
            try:
                line += f"{self.tuesday[i]},"
            except:
                line += ","
            try:
                line += f"{self.wednesday[i]},"
            except:
                line += ","
            try:
                line += f"{self.thursday[i]},"
            except:
                line += ","
            try:
                line += f"{self.friday[i]},"
            except:
                line += ""
            line += "\n"
            lines.append(line)

        with open(f"{file_name}", mode="w", encoding="UTF-8") as file:
            for line in lines:
                file.write(line)
