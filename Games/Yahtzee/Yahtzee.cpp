#include "Yahtzee.h"

int main() {

    // SET RANDOM SEED
    srand(time(0));
    
    // ESTABLISH VARIABLES
    vector<int> my_dice(0);
    vector<int> saved_dice = {0,0,0,0,0};

    // GET ROLL
    for (int i = 0; i < 3; i++) {
        my_dice = rollDice(saved_dice);
        displayDice(my_dice);
    }

    return 0;
}
