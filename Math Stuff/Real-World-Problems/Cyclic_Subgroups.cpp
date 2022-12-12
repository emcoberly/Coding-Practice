#include <iostream>
#include <vector>

using namespace std;

int GCD(int num1, int num2);
int LCM(int num1, int num2);
vector<int> factors(int num1);

int main() {
    int num1, num2;
    vector<int> factor_num1, factor_num2;
    cout << "Enter first number: ";
    cin >> num1;
    cout << "Enter second number: ";
    cin >> num2;
    factor_num1 = factors(num1);
    factor_num2 = factors(num2);
    return 0;
}

int GCD(int num1, int num2) {
    while (num1 != num2) {
        if (num1 > num2) {
            num1 -= num2;
        } else if (num2 > num1) {
            num2 -= num1;
        }
    }
    return num1;
}

int LCM(int num1, int num2) {
    return (num1 * num2 / GCD(num1, num2));
}
