#include "Yahtzee.h"
#include "rollDice.cpp"

int main() {

    srand(time(0));

    vector<int> dice(5);

    dice = rollDice(dice);

    for (int i = 0; i < 5; i++) {
        cout << dice.at(i) << " ";
    } cout << endl;

    return 0;
}