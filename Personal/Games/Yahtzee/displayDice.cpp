#include "Yahtzee.h"

void displayDice(vector<int> my_dice) {
    
    char blank = ' ';
    vector<char> die1(9), die2(9), die3(9), die4(9), die5(9);
    vector<vector<char>> dice = {die1, die2, die3, die4, die5};

    // CREATE 5 EMPTY DICE
    for (int d = 0; d < 5; d++) {
        fill(dice.at(d).begin(), dice.at(d).end(), blank);
    }

    // FILL DICE WITH DOTS ACCORDING TO THE DICE ROLLED
    for (int i = 0; i < 5; i++) {
        switch(my_dice.at(i)) {
            // ODD NUMBERS
            case 5:
                dice.at(i).at(0) = 'O';
                dice.at(i).at(8) = 'O';
            case 3:
                dice.at(i).at(2) = 'O';
                dice.at(i).at(6) = 'O';
            case 1:
                dice.at(i).at(4) = 'O';
                break;

            // EVEN NUMBERS
            case 6:
                dice.at(i).at(3) = 'O';
                dice.at(i).at(5) = 'O';
            case 4:
                dice.at(i).at(0) = 'O';
                dice.at(i).at(8) = 'O';
            case 2:
                dice.at(i).at(2) = 'O';
                dice.at(i).at(6) = 'O';
                break;
            
            default:
                cout << "Invalid dice." << endl;
                break;
        }
    }

    // DISPLAY ACTUAL DICE
    for (int r0 = 0; r0 < 5; r0++) {
        cout << " -------  ";
    } cout << endl;
    for (int r1 = 0; r1 < 5; r1++) {
        cout << "| " << dice.at(r1).at(0) << " " << dice.at(r1).at(1) << " " << dice.at(r1).at(2) << " | ";
    } cout << endl;
    for (int r2 = 0; r2 < 5; r2++) {
        cout << "| " << dice.at(r2).at(3) << " " << dice.at(r2).at(4) << " " << dice.at(r2).at(5) << " | ";
    } cout << endl;
    for (int r3 = 0; r3 < 5; r3++) {
        cout << "| " << dice.at(r3).at(6) << " " << dice.at(r3).at(7) << " " << dice.at(r3).at(8) << " | ";
    } cout << endl;
    for (int r4 = 0; r4 < 5; r4++) {
        cout << " -------  ";
    } cout << endl << endl;

}