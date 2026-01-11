"""
Main file for assigning days off to camp staff.
"""

import sys

import calendar
import staff


def assign():
    """
    Assigns days off for staff members found in a specified CSV file.
    """

    staff_list = []
    import_filename = sys.argv[1]
    export_filename = sys.argv[2]

    with open(import_filename, encoding="UTF-8") as file:
        for row in file:
            row = row.split(",")
            staff_member = staff.Staff(row)
            staff_list.append(staff_member)
        staff_list = staff_list[1:]

    # day_1_calendar = calendar.Calendar()
    # for staff_member in staff_list:
    #     day_1_calendar.assign_day_off(staff_member, staff_member.day_1)
    #     print(f"My name is {staff_member.name}, and my happiness is {staff_member.happiness}/5.")
    # day_1_calendar.export(export_filename)

    day_2_calendar = calendar.Calendar()
    for staff_member in staff_list:
        day_2_calendar.assign_day_off(staff_member, staff_member.day_2)
        print(
            f"My name is {staff_member.name}, and my happiness is {staff_member.happiness}/5."
        )
    day_2_calendar.export(export_filename)
