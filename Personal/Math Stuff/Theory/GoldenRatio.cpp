#include <cmath>
#include <iomanip>
#include <iostream>
using namespace std;

void fibonacci(double &num1, double &num2);

int main() {
    int i = 1, j = 1, precision = 25;
    double x = 1.0, y = 1.0;
    double ratio = 0.0, golden_ratio = 0.5*(1+sqrt(5));
    int array[i][j];
    int user_input;
    cout << "How far will Fibonacci go to find the golden ratio? -> ";
    cin >> user_input;
    for (int i = 1; i <= user_input; i++) {
        fibonacci(x,y);
    }
    ratio = y / x;
    cout << "Fibonacci's estimate:  " << fixed << setprecision(precision) << ratio << endl;
    cout << "Actual amount:         " << fixed << setprecision(precision) << (1 + sqrt(5))/2 << endl;
    cout << "Percent error:         " << fixed << setprecision(precision) << (1 - ratio/golden_ratio)*100 << "%" << endl;
    return 0;
}

void fibonacci(double &num1, double &num2) {
    double hold_num = num2;
    num2 += num1;
    num1 = hold_num;
}