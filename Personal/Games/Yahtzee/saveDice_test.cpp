#include "Yahtzee.h"
#include "saveDice.cpp"
#include "rollDice.cpp"
#include "displayDice.cpp"

int main() {

    srand(time(0));
    vector<int> my_roll(5);

    for (int roll = 0; roll < 3; roll++) {
        my_roll = rollDice(my_roll);
        displayDice(my_roll);
        saveDice(my_roll);

        for (int i = 0; i < 5; i++) {
            cout << my_roll.at(i) << " ";
        } cout << endl;
    }

    return 0;
}