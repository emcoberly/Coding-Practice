#include "Yahtzee.h"
#include "displayDice.cpp"
#include "rollDice.cpp"

int main() {

    srand(time(0));

    vector<int> dice(5);
    
    dice = rollDice();
    displayDice(dice);

    return 0;
}