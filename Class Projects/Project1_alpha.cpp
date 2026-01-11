#include <iostream>
using namespace std;

int main() {
  int a, b, c;
  int x = 0, y = 0, xAlt = 0, yAlt = 0;
  cout << "For the equation 'ax + by = c':" << endl << endl;
  cout << "Enter a number 'a': ";
  cin >> a;
  cout << "Enter a number 'b': ";
  cin >> b;
  cout << "Enter a number 'c': ";
  cin >> c;
  int position = a, altPosition = a;
  while (true) {
    if ((position - c) % b != 0) {
      x += 1;
      position *= x;
    }
    if ((position - c) % b == 0) {
      y = (position - c) / b * -1;
      break;
    }
    position = a;
  }
  while (true) {
    if ((altPosition - c) % b != 0) {
      xAlt -= 1;
      altPosition *= xAlt;
    }
    if ((altPosition - c) % b == 0) {
      yAlt = (altPosition - c) / b * -1;
      break;
    }
    altPosition = a;
  }
  cout << "\nx = " << x << ", y = " << y << endl;
  cout << a << "(" << x << ") + " << b << "(" << y << ") = " << c << endl;
  cout << "\nx = " << xAlt << ", y = " << yAlt << endl;
  cout << a << "(" << xAlt << ") + " << b << "(" << yAlt << ") = " << c << endl << endl;

  return 0;
}