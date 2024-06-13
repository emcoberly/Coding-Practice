#include <iostream>
#include <list>

using namespace std;

int main() {

    // ESTABLISH VARIABLES
    int prisoners, skip_number;
    bool invalid_prisoners = true, invalid_skip_num = true;
    list<char> prisoner_names(0);

    // CHECK FOR VALID PRISONER NUMBER
    do {
        cout << "Enter a number of prisoners (at least 3): ";
        cin >> prisoners;
        if (cin.fail()) {
            cout << "Not an integer. Please try again." << endl;
            cin.clear();
            cin.ignore(1000,'\n');
            continue;
        } else if (prisoners < 3) {
            cout << "Too few prisoners. Please try again." << endl;
            continue;
        } else {
            invalid_prisoners = false;
        }
    } while (invalid_prisoners);
    
    // CHECK FOR VALID SKIP NUMBER
    do{
        cout << "Enter a skip number (at least 2): ";
        cin >> skip_number;
        if (cin.fail()) {
            cout << "Not an integer. Please try again." << endl;
            cin.clear();
            cin.ignore(1000,'\n');
            continue;
        } else if (skip_number < 2) {
            cout << "Skip number too small. Please try again." << endl;
            continue;
        } else {
            invalid_skip_num = false;
        }
    } while (invalid_skip_num);

    // CREATE LIST OF PRISONERS A-Z AND a-z
    for (int i = 0; i < prisoners; i++) {
        if (i < 26) {
            prisoner_names.push_back(i + 65);
        } else {
            prisoner_names.push_back(i + 97);
        }
    }

    // START KILLING
    for (int j = 0; j < prisoners - 1; j++) {
        for (int k = 1; k <= skip_number; k++) {
            prisoner_names.push_back(prisoner_names.front());
            prisoner_names.pop_front();
        }
        prisoner_names.pop_back();
    }

    // OUTPUT SURVIVOR
    cout << "Surviving prisoner: " << prisoner_names.front() << endl;

    return 0;
}

// This problem follows the formula f(n) = 2(n+1-2^floor(log_2(n+1)))+1
