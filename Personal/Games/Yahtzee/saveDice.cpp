#include "Yahtzee.h"

void saveDice(vector<int> &my_dice) {
    int die_save = -1;
    vector<int> keep_dice(0);
    vector<int> temp_dice = my_dice;

    cout << "Enter the dice you wish to keep as a spaced list of up to 5 dice;" << endl;
    cout << "Enter \'0\' as the last number to stop saving: " << endl;
    while ((die_save != 0) && (keep_dice.size() < 5)) {
        bool invalid_input = true;
        cout << "Die -> ";
        cin >> die_save;
        if (cin.fail()) {
            cin.clear();
            cin.ignore(1000,'\n');
            cout << "You are only allowed to enter integers." << endl;
        } else if ((die_save < 0) || (die_save > 6)) {
            cout << "You are only allowed to enter digits from 1-6." << endl;
        } else {
            for (int i = 0; i < 5; i++) {
                if (die_save == temp_dice.at(i)) {
                    keep_dice.push_back(die_save);
                    temp_dice.at(i) = 0;
                    invalid_input = false;
                    break;
                }
            }
            if (invalid_input) {
                cout << "That number does not appear in your roll." << endl;
            }
        }
    }
    for (int j = 0; j < 5; j++) {
        if (temp_dice.at(j) != 0) {
            my_dice.at(j) = 0;
        }
    }
}
