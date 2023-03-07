#include <iostream>
#include <list>
#include <vector>

using namespace std;

int main() {

    // ESTABLISH VARIABLES
    int prisoners, skip_number;
    bool invalid_prisoners = true, invalid_skip_num = true;
    list<int> prisoner_names(0);
    vector<int> Josephus(0), Friend(0);

    // CHECK FOR VALID PRISONER NUMBER
    do {
        cout << "Enter max number of prisoners (at least 3): ";
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
    do {
        cout << "Enter a constant skip number (at least 2): ";
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

    for (int p = 3; p <= prisoners; p++) {
        // CREATE LIST OF PRISONERS NUMBERED STARTING AT 1
        for (int i = 1; i <= p; i++) {
            prisoner_names.push_back(i);
        }

        // START KILLING
        for (int j = 0; j < p - 1; j++) {
            for (int k = 1; k <= skip_number; k++) {
                prisoner_names.push_back(prisoner_names.front());
                prisoner_names.pop_front();
            }
            if (j == (p - 2)) {
                Friend.push_back(prisoner_names.back());
            }
            prisoner_names.pop_back();
        }
        Josephus.push_back(prisoner_names.front());
        cout << "J(" << p << "," << skip_number << ")\t= " << prisoner_names.front() << endl;
        prisoner_names.pop_front();
    }

    for (int jo = 0; jo < Josephus.size(); jo++) {
        cout << "J(" << jo + 3 << "," << skip_number << ")\t= " << Josephus.at(jo) <<
            "\tF(" << jo + 3 << "," << skip_number << ")\t= " << Friend.at(jo) << endl;
        cout << "\t\t\tJ(" << jo + 3 << "," << skip_number << ") - F(" << jo + 3 << "," << skip_number <<
            ") = " << Josephus.at(jo) - Friend.at(jo) << endl;
    }

    return 0;
}