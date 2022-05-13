#include "Yahtzee.h"
#include "scoreboard.cpp"
#include "unistd.h"

int main() {
    map<string,int> my_scores = {
        {"Aces",   -1},
        {"Deuces", -1},
        {"Threes", -1},
        {"Fours",  -1},
        {"Fives",  -1},
        {"Sixes",  -1},
        {"Bonus",  -1},
        {"Three of a Kind", -1},
        {"Four of a Kind",  -1},
        {"Full House",      -1},
        {"Small Straight",  -1},
        {"Large Straight",  -1},
        {"Yahtzee",         -1},
        {"Yahtzee Bonus",    0},
        {"Chance",          -1},
    };

    for (int i = 0; i < 13; i++) {
        if (i == 0) {
            my_scores["Aces"] = 2;
        } else if (i == 1) {
            my_scores["Large Straight"] = 40;
        } else if (i == 2) {
            my_scores["Yahtzee"] = 50;
        } else if (i == 3) {
            my_scores["Threes"] = 9;
        } else if (i == 4) {
            my_scores["Fours"] = 16;
        } else if (i == 5) {
            my_scores["Four of a Kind"] = 23;
        } else if (i == 6) {
            my_scores["Fives"] = 10;
        } else if (i == 7) {
            my_scores["Sixes"] = 18;
        } else if (i == 8) {
            my_scores["Three of a Kind"] = 16;
        } else if (i == 9) {
            my_scores["Chance"] = 30;
            my_scores["Yahtzee Bonus"] += 100;
        } else if (i == 10) {
            my_scores["Full House"] = 25;
        } else if (i == 11) {
            my_scores["Deuces"] = 8;
        } else if (i == 12) {
            my_scores["Small Straight"] = 30;
        }
        scoreboard(my_scores);
        sleep(1);
    }

    return 0;
}