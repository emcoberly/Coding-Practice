#include "Yahtzee.h"
#include "sumDice.cpp"

int main() {
    vector<int> dice = {1, 4, 5, 5, 6};
    int dice_sum = sumDice(dice);
    cout << "Dice sum: " << dice_sum << endl;
    return 0;
}