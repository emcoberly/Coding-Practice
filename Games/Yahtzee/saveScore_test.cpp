#include "Yahtzee.h"
#include "saveDice.cpp"
#include "rollDice.cpp"
#include "displayDice.cpp"
#include "scoreboard.cpp"
#include "saveScore.cpp"
#include "sumDice.cpp"

int main() {

    srand(time(0));
    vector<int> my_roll(5);
    string input;
    map<string,int> scores = {
        {"Aces",    3},
        {"Deuces", -1},
        {"Threes", -1},
        {"Fours",  16},
        {"Fives",  -1},
        {"Sixes",  18},
        {"Bonus",  -1},
        {"Three of a Kind", 14},
        {"Four of a Kind",  -1},
        {"Full House",      -1},
        {"Small Straight",  30},
        {"Large Straight",  -1},
        {"Yahtzee",         -1},
        {"Yahtzee Bonus",    0},
        {"Chance",          -1},
    };

    for (int roll = 1; roll < 4; roll++) {
        bool invalid_input = true;
        bool turn_end = false;
        my_roll = rollDice(my_roll);
        displayDice(my_roll);
        scoreboard(scores);
        if (roll < 3) {
            cout << "Would you like to roll again or take your score now?" << endl;
            do {
                cout << "(roll/score) -> ";
                cin >> input;
                if (input == "roll") {
                    saveDice(my_roll);
                    invalid_input = false;
                } else if (input == "score") {
                    turn_end = saveScore(my_roll, scores, roll);
                    invalid_input = false;
                } else {
                    cout << "Invalid input. Please try again." << endl;
                    cin.clear();
                    cin.ignore(1000, '\n');
                }
            } while (invalid_input);
        }
        if (turn_end) {
            break;
        }
    }

    return 0;
}
