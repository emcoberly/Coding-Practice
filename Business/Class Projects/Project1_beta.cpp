#include <iostream>
using namespace std;

int main() {
  int a, b, c, position = 0, altPosition = 0;
  int x = 0, y = 0, altX = 0, altY = 0;
  cout << "For the equation 'ax + by = c':" << endl << endl;
  cout << "Enter a number 'a': ";
  cin >> a;
  cout << "Enter a number 'b': ";
  cin >> b;
  cout << "Enter a number 'c': ";
  cin >> c;
  while (true) {
    if (position < c) {
      position += a;
      x += 1;
    } else if (position > c) {
      position -= b;
      y -= 1;
    } else {
      break;
    }
  }
  while (true) {
    if (altPosition < c) {
      altPosition += b;
      altY += 1;
    } else if (altPosition > c) {
      altPosition -= a;
      altX -= 1;
    } else {
      break;
    }
  }
  cout << "\nx = " << x << ", " << "y = " << y << endl;
  cout << a << "(" << x << ") + " << b << "(" << y << ") = " << c << endl;
  cout << "\nx = " << altX << ", " << "y = " << altY << endl;
  cout << a << "(" << altX << ") + " << b << "(" << altY << ") = " << c << endl
       << endl;

  return 0;
}