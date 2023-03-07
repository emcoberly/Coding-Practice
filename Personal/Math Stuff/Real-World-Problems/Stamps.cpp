#include <cmath>
#include <iostream>
using namespace std;

int main() {
    int stamp1 = 10;
    int stamp2 = 12;
    int consecutive = 0;
    int number = 1, temp_num;
    while (number < 100) {
        temp_num = number;
        while (temp_num >= 0) {
            if (temp_num % stamp2 != 0) {

                cout << "\t\t" << temp_num % stamp2 << endl;

                temp_num -= stamp1;
                if (temp_num < 0) {
                    consecutive = 0;
                }
            } else {
                consecutive++;
                break;
            }
        }

        cout << number << "\t" << consecutive << endl;

        if (consecutive == stamp1) {
            break;
        }
        number++;
    }
    cout << "Your number: " << number - stamp1 + 1 << endl;
}