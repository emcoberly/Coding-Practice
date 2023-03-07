#include "Yahtzee.h"

int sumDice(vector<int> my_dice) {
    int temp_sum = 0;
    for (int i = 0; i < 5; i++) {
        temp_sum += my_dice.at(i);
    }
    return temp_sum;
}
