#include "Yahtzee.h"

vector<int> rollDice(vector<int> ignore) {

    vector<int> rolled_dice(5);

    for (int i = 0; i < 5; i++) {
        if (ignore.at(i) == 0) {
            ignore.at(i) = rand() % 6 + 1;
        }
        rolled_dice.at(i) = ignore.at(i);
    }

    return rolled_dice;
}
