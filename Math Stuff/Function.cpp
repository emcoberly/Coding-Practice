#include <iostream>

using namespace std;

int main() {
    int x_val;
    int y_val;

    for (int y = 5; y >= 0; y--) {
        for (int x = 0; x <= 5; x++) {
            x_val = -x + x * y;
            y_val = 4 * y - 2 * x * y;
            cout << "<" << x_val << "," << y_val << ">   \t";
        } cout << endl;
    }

    return 0;
}