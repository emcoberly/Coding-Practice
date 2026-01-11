/*************************************************************************
 *
 * hw04: Determine a final letter grade and if the user needs to take
 *       the final exam.
 *
 * File Name: gradeCalculator.cpp
 * Name:      Eddie Coberly
 * Course:    CPTR 141
 *
 */

#include <iostream>
using namespace std;

int main() {

  // define variables
  double myTest, myHomework, myParticipation, myAverage;
  bool validTest = false, validHomework = false, validParticipation = false;
  char finalGrade = 0;

  // gather input
  cout << "Enter your test, homework, and participation averages separated by "
          "spaces: ";
  cin >> myTest >> myHomework >> myParticipation;

  // validate that input
  if (myTest <= 100 && myTest >= 0) {
    validTest = true;
  }
  if (myHomework <= 100 && myHomework >= 0) {
    validHomework = true;
  }
  if (myParticipation <= 100 && myParticipation >= 0) {
    validParticipation = true;
  }
  if (validTest && validHomework && validParticipation) {
    myAverage = myTest * 0.45 + myHomework * 0.35 + myParticipation * 0.20;
    if (myAverage >= 90) {
      finalGrade += 65;
    } else if (myAverage >= 80) {
      finalGrade += 66;
    } else if (myAverage >= 70) {
      finalGrade += 67;
    } else if (myAverage >= 60) {
      finalGrade += 68;
    } else {
      finalGrade += 70;
    }
  } else {
    cout << "All averages must be between 0 and 100." << endl;
  }

  // branching statements to produce output
  if (validTest && validHomework && validParticipation) {
    if (finalGrade == 65) {
      cout << "You have an " << finalGrade
           << " in the class and do not need to take the final." << endl;
    } else if (finalGrade == 70) {
      cout << "You have an " << finalGrade
           << " in the class and you must take the final." << endl;
    } else {
      cout << "You have a " << finalGrade
           << " in the class and you must take the final." << endl;
    }
  }

  return 0;
}