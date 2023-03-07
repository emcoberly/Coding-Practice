/********************************
Eddie Coberly
CPTR 141
Project 2
9 February 2021
This project is designed to imitate an ancient form of two-factor
multiplication. This method is unlike any of the modern, conventional methods:
    - The user inputs two whole numbers.
    - One number is doubled, while the other number is halved and truncated
until it reaches 1.
    - These numbers are sorted into a doubling column and a halving column.
    - For every odd number in the halving column, the corresponding number in
the doubling column is added.
    - The sum of all numbers accepted is the product of the two input numbers.
********************************/

#include <iomanip>
#include <iostream>
#include <string>
using namespace std;

int main() {

  // Set up the loop to prompt a repeat
  char doAgain;

  do {

    // Gather and verify input
    int userFactor1, userFactor2, productSum = 0;
    do {
      cout << "Please enter two non-zero integers separated by spaces: ";
      cin >> userFactor1 >> userFactor2;
      if (userFactor1 == 0 || userFactor2 == 0) {
        cout << "Both of your integers must be non-zero." << endl;
      }
    } while (userFactor1 == 0 || userFactor2 == 0);

    // Build table
    int setWidth = to_string(userFactor1 * userFactor2).length() + 1;
    while (userFactor2 != 0) {
      char sumOperation = ' ';
      if (userFactor2 % 2 == 1) {
        productSum += userFactor1;
        sumOperation = '+';
      } else if (userFactor2 % 2 == -1) {
        productSum -= userFactor1;
        sumOperation = '-';
      }
      cout << sumOperation << setw(setWidth) << userFactor1 << " |"
           << setw(setWidth) << userFactor2 << endl;
      userFactor1 *= 2;
      userFactor2 /= 2;
    }

    // Tell the user what the product is
    cout << "The product is: " << productSum << endl << endl;

    // Ask to do it again
    cout << "Enter 'y' to repeat, or enter anything else to quit: ";
    cin >> doAgain;
    cin.clear();
    cout << endl;

  } while (doAgain == 'y');

  // End of program
  return 0;
}