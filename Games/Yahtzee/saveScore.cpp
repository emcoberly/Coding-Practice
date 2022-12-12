#include "Yahtzee.h"

void saveScore(vector<int> my_dice, map<string,int> &player_score, int turns_taken, bool &finish_turn) {

    // SEND DICE NUMBERS TO MAP FOR SCORE OPTION COMPARISONS
    map<string,int> dice_nums {
        {"one",     0},
        {"two",     0},
        {"three",   0},
        {"four",    0},
        {"five",    0},
        {"six",     0}
    };
    for (int i = 0; i < 5; i++) {
        if (my_dice.at(i) == 1) {
            dice_nums["one"]++;
        } else if (my_dice.at(i) == 2) {
            dice_nums["two"]++;
        } else if (my_dice.at(i) == 3) {
            dice_nums["three"]++;
        } else if (my_dice.at(i) == 4) {
            dice_nums["four"]++;
        } else if (my_dice.at(i) == 5) {
            dice_nums["five"]++;
        } else if (my_dice.at(i) == 6) {
            dice_nums["six"]++;
        }
    }

    string score_type;
    string confirm_score;
    bool invalid_input = true;

    // SCAN FOR YAHTZEE AND BONUS, IMPORTANT FOR LATER
    bool yahtzee = false;
    for (const auto& kv : dice_nums) {
        if (kv.second == 5) {
            yahtzee = true;
        }
    }
    bool yahtzee_bonus = yahtzee && (player_score["Yahtzee"] != -1);

    cout << "What score would you like to save?" << endl;
    cout << "Enter as written on the scorepad. Use \'-\' for spaces. Case-sensitive." << endl;
    if (turns_taken < 3) {
        cout << "(Enter \'Cancel\' to cancel return to options menu.)" << endl;
    }
    do {
        cin.clear();
        cin.ignore(1000,'\n');
        int points_available = 0;
        cout << "-> ";
        cin >> score_type;

        if (score_type == "Cancel") {
            return;
        } else if (player_score[score_type] != -1) {
            cout << "You have already taken that score. Save something else." << endl;
        } else {
            if (score_type == "Aces") {
                points_available = dice_nums["one"];
            } else if (score_type == "Deuces") {
                points_available = dice_nums["two"] * 2;
            } else if (score_type == "Threes") {
                points_available = dice_nums["three"] * 3;
            } else if (score_type == "Fours") {
                points_available = dice_nums["four"] * 4;
            } else if (score_type == "Fives") {
                points_available = dice_nums["five"] * 5;
            } else if (score_type == "Sixes") {
                points_available = dice_nums["six"] * 6;
            } else if (score_type == "Three-of-a-Kind") {
                for (const auto& kv : dice_nums) {
                    if (kv.second >= 3) {
                        points_available = sumDice(my_dice);
                        break;
                    }
                }
            } else if (score_type == "Four-of-a-Kind") {
                for (const auto& kv : dice_nums) {
                    if (kv.second >= 4) {
                        points_available = sumDice(my_dice);
                        break;
                    }
                }
            } else if (score_type == "Full-House") {
                bool three_set = false, two_set = false;
                for (const auto& kv : dice_nums) {
                    if (kv.second == 3) {
                        three_set = true;
                    } else if (kv.second == 2) {
                        two_set = true;
                    }
                }
                if ((three_set && two_set) || yahtzee_bonus) {
                    points_available = 25;
                }
            } else if (score_type == "Small-Straight") {
                // SMALL STRAIGHTS MUST CONTAIN 3 AND 4 AND HAVE AT LEAST ONE 1/2, 2/5, OR 5/6 PAIR
                bool small_12 = (dice_nums["one"] > 0) && (dice_nums["two"] > 0);
                bool small_25 = (dice_nums["two"] > 0) && (dice_nums["five"] > 0);
                bool small_56 = (dice_nums["five"] > 0) && (dice_nums["six"] > 0);
                bool small_req = (dice_nums["three"] > 0) && (dice_nums["four"] > 0);
                if ((small_req && (small_12 || small_25 || small_56)) || yahtzee_bonus) {
                    points_available = 30;
                }
            } else if (score_type == "Large-Straight") {
                // LARGE STRAIGHTS MUST CONTAIN 2-5 AND EITHER 1 OR 6
                bool large_1 = dice_nums["one"] == 1;
                bool large_6 = dice_nums["six"] == 1;
                bool large_req = (dice_nums["two"] == 1) && (dice_nums["three"] == 1) && (dice_nums["four"] == 1) && (dice_nums["five"] == 1);
                if ((large_req && (large_1 || large_6)) || yahtzee_bonus) {
                    points_available = 40;
                }
            } else if (score_type == "Yahtzee") {
                if (yahtzee) {
                    points_available = 50;
                }
            } else if (score_type == "Chance") {
                points_available = sumDice(my_dice);
            }
            cout << "Take " << score_type << " for " << points_available << " point";
            if (points_available != 1) { cout << "s"; }     // CHECK FOR PLURALIZATION LOL
            cout << "?" << endl;
            cout << "(Yes/No) -> ";
            cin >> confirm_score;
            if (confirm_score == "Yes") {
                invalid_input = false;
                finish_turn = true;
                player_score[score_type] = points_available;
                return;
            }
        }
    } while (invalid_input);
}
