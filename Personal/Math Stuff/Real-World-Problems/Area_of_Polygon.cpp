#include <cmath>
#include <iomanip>
#include <iostream>
using namespace std;

int main() {

  // Assign variables
  int sideNumber, setPrecision;
  double sideLength, polyArea, interAngle, interAltitude, intTriangle;

  // Prompt User input
  cout << "Enter the number of sides: ";
  cin >> sideNumber;
  cout << "Enter the side length: ";
  cin >> sideLength;
  cout << "Enter the number of decimal places: ";
  cin >> setPrecision;

  // Perform calculation
  interAngle = M_PI * (sideNumber - 2) / sideNumber / 2;
  interAltitude = (sideLength / 2) * tan(interAngle);
  intTriangle = (sideLength / 2) * interAltitude;
  polyArea = intTriangle * sideNumber;

  // Tell User the area
  cout << "\nThe total area is: " << fixed << setprecision(setPrecision)
       << polyArea << endl;

  return 0;
}