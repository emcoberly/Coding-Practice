#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

double SquareRoot(double square);
double CubeRoot(double cube);
double Root(double base, int exponent);

int main() {
    double user_num;
    int user_power;
    while (true) {
        cout << "Enter a number (0 to quit):  ";
        cin >> user_num;
        if (user_num == 0) {
            break;
        }
        cout << "Enter \'n\' for an nth root: ";
        cin >> user_power;
        cout << user_power << "th root:\t" << fixed << setprecision(10) << Root(user_num,user_power) << endl;
        cout << "Actual answer:\t" << fixed << setprecision(10) << pow(user_num,(1.0/user_power)) << endl;
        // cout << "The roots of " << user_num << " are:" << endl;
        // cout << "Square root:  \t" << fixed << setprecision(10) << SquareRoot(user_num) << endl;
        // cout << "Actual answer:\t" << fixed << setprecision(10) << sqrt(user_num) << endl;
        // cout << "Cube root:    \t" << fixed << setprecision(10) << CubeRoot(user_num) << endl;
        // cout << "Actual answer:\t" << fixed << setprecision(10) << pow(user_num,(1.0/3.0)) << endl;
    }
}

double SquareRoot(double square) {
    double divisor = square;
    double quotient;
    for (int i = 0; i < 19; i++) {
        quotient = square / divisor;
        divisor = (divisor + quotient) / 2.0;
    }
    return quotient;
}

double CubeRoot(double cube) {
    double divisor = cube;
    double quotient;
    for (int i = 0; i < 39; i++) {
        quotient = cube / (divisor * divisor);
        divisor = (divisor + quotient) / 2.0;
    }
    return quotient;
}

double Root(double base, int exponent) {
    double divisor = base, temp_div;
    double quotient;
    int temp_prec = 25, precision = 1;
    for (int p = 1; p <= exponent; p++) {
        precision *= temp_prec;
    }
    for (int i = 0; i < precision; i++) {
        temp_div = 1;
        for (int j = 1; j < exponent; j++) {
            temp_div *= divisor;
        }
        quotient = base / temp_div;
        divisor = (divisor + quotient) / 2.0;
    }
    return quotient;
}
