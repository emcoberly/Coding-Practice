#include <iostream>
#include <cmath>
using namespace std;

void ThreeXPlusOne(int num1, int &three, int &two, int &greatest);

int main() {
    
    char doAgain = 'y';
    do {
        int number, large_num;
        int mult_three = 0, div_2 = 0;
        cout << "Enter a number greater than 1: ";
        cin >> number;

        ThreeXPlusOne(number, mult_three, div_2, large_num);

        cout << "Number of multiplications: " << mult_three << endl;
        cout << "Number of divisions: " << div_2 << endl;
        cout << "Total iterations: " << mult_three + div_2 << endl;
        cout << "Highest number reached: " << large_num << endl << endl;

        cout << "Would you like to do this again? (y/n) -> ";
        cin >> doAgain;
        cout << endl;

    } while (doAgain == 'y');

    return 0;

}

//void check(char num1) {
//   if
//}

void ThreeXPlusOne(int num1, int &three, int &two, int &greatest) {
    greatest = num1;
    while (num1 != 1) {
        if (num1 % 2 == 0) {
            num1 = num1 / 2;
            two++;
        } else {
            num1 = 3 * num1 + 1;
            three++;
        }
        if (num1 > greatest) {
            greatest = num1;
        }
    }
}