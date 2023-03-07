#include <iostream>
using namespace std;

int main() {

    int fibCount = 2, userCount;
    bool passCheck = false;
    cout << "This is the Fibonacci sequence." << endl;
    // cout << "How many numbers would you like to print? ";
    // cin >> userCount;

    while(passCheck == false) {
        cout << "Which number of digit up to 70 would you like to print? ";
        cin >> userCount;
        if(userCount <= 70) {
            passCheck = true;
        } else {
            cout << "Please enter a number up to 70." << endl;
        }
    }

    long long int fib1 = 1, fib2 = 1, fib3, endLine = 2;
    // cout << endl << fib1 << " " << fib2 << " ";
    while(passCheck) {
        fib3 = fib1 + fib2;
        // cout << fib3 << " ";
        fib1 = fib2;
        fib2 = fib3;
        endLine += 1;
        fibCount += 1;
        /*if(endLine == 10) {
            endLine = 0;
            cout << endl;
        }*/
        if(userCount == 1 || userCount == 2) {
            cout << "The number is 1." << endl;
            break;
        } else if(fibCount == userCount) {
            cout << "The number is: " << fib3 << endl;
            break;
        }
    }

    return 0;
}