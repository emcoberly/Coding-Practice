#include "Yahtzee.h"

void scoreboard(map<string,int> scores) {

    int top_subtotal = -1;
    int top_half_score = -1;
    int bottom_half_score = -1;
    int total_score = -1;
    bool valid_top_score = (scores["Aces"] > -1) && (scores["Deuces"] > -1) && (scores["Threes"] > -1) &&
                            (scores["Fours"] > -1) && (scores["Fives"] > -1) && (scores["Sixes"] > -1);
    bool valid_bottom_score = ((scores["Three-of-a-Kind"] > -1) && (scores["Four-of-a-Kind"] > -1) && (scores["Full-House"] > -1) &&
                                (scores["Small-Straight"] > -1) && (scores["Large-Straight"] > -1) && (scores["Yahtzee"] > -1) &&
                                (scores["Chance"] > -1));

    // HEADER
    cout << "        Roll        |    Score    " << endl;
    cout << "==================================" << endl;

    // TOP HALF
    cout << "Aces                |      ";
    if (scores["Aces"] > -1) {
        cout << scores["Aces"];
    } cout << endl;
    cout << "Deuces              |      ";
    if (scores["Deuces"] > -1) {
        cout << scores["Deuces"];
    } cout << endl;
    cout << "Threes              |      ";
    if (scores["Threes"] > -1) {
        cout << scores["Threes"];
    } cout << endl;
    cout << "Fours               |      ";
    if (scores["Fours"] > -1) {
        cout << scores["Fours"];
    } cout << endl;
    cout << "Fives               |      ";
    if (scores["Fives"] > -1) {
        cout << scores["Fives"];
    } cout << endl;
    cout << "Sixes               |      ";
    if (scores["Sixes"] > -1) {
        cout << scores["Sixes"];
    } cout << endl;

    // SET TOP SUBTOTAL
    top_subtotal = scores["Aces"] + scores["Deuces"] + scores["Threes"] + scores["Fours"] + scores["Fives"] + scores["Sixes"];

    // DISPLAY TOP SUBTOTAL IF READY
    cout << "----------------------------------" << endl;
    cout << "Subtotal            |      ";
    if (valid_top_score) {
        cout << top_subtotal;
    } cout << endl;

    // SET BONUS IF READY
    if (valid_top_score) {
        if (top_subtotal >= 63) {
            scores["Bonus"] = 35;
        } else {
            scores["Bonus"] = 0;
        }
    }

    // DISPLAY BONUS IF APPLICABLE
    cout << "Bonus               |      ";
    if (scores["Bonus"] > -1) {
        cout << scores["Bonus"];
    } cout << endl;

    // SET TOP SCORE
    if (valid_top_score && (scores["Bonus"] > -1) && (top_half_score < 0)) {
        top_half_score = top_subtotal + scores["Bonus"];
    }

    // DISPLAY TOP SCORE IF READY
    cout << "Top Half Score      |      ";
    if (top_half_score > -1) {
        cout << top_half_score;
    } cout << endl;
    cout << "==================================" << endl;

    // BOTTOM HALF
    cout << "Three of a Kind     |      ";
    if (scores["Three-of-a-Kind"] > -1) {
        cout << scores["Three-of-a-Kind"];
    } cout << endl;
    cout << "Four of a Kind      |      ";
    if (scores["Four-of-a-Kind"] > -1) {
        cout << scores["Four-of-a-Kind"];
    } cout << endl;
    cout << "Full House          |      ";
    if (scores["Full-House"] > -1) {
        cout << scores["Full-House"];
    } cout << endl;
    cout << "Small Straight      |      ";
    if (scores["Small-Straight"] > -1) {
        cout << scores["Small-Straight"];
    } cout << endl;
    cout << "Large Straight      |      ";
    if (scores["Large-Straight"] > -1) {
        cout << scores["Large-Straight"];
    } cout << endl;
    cout << "Yahtzee             |      ";
    if (scores["Yahtzee"] > -1) {
        cout << scores["Yahtzee"];
    } cout << endl;

    // CONDITIONAL INCLUSION OF YAHTZEE BONUS
    if (scores["Yahtzee Bonus"] > 0) {
        cout << "Yahtzee Bonus       |     " << scores["Yahtzee Bonus"] << endl;
    }

    cout << "Chance              |      ";
    if (scores["Chance"] > -1) {
        cout << scores["Chance"];
    } cout << endl;
    cout << "----------------------------------" << endl;

    // FINAL SCORES
    // SET BOTTOM SCORE
    bottom_half_score = scores["Three-of-a-Kind"] + scores["Four-of-a-Kind"] + scores["Full-House"] +
                        scores["Small-Straight"] + scores["Large-Straight"] + scores["Yahtzee"] +
                        scores["Yahtzee Bonus"] + scores["Chance"];

    // DISPLAY BOTTOM SCORE IF READY
    cout << "Bottom Half Score   |      ";
    if (valid_bottom_score) {
        cout << bottom_half_score;
    } cout << endl;

    // DISPLAY TOP SCORE IF READY
    cout << "Top Half Score      |      ";
    if (top_half_score > -1) {
        cout << top_half_score;
    } cout << endl;
    cout << "==================================" << endl;

    // SET TOTAL SCORE IF READY
    if (valid_bottom_score && (top_half_score > -1)) {
        total_score = top_half_score + bottom_half_score;
    }

    // DISPLAY TOTAL SCORE IF READY
    cout << "Total Score         |      ";
    if (total_score > -1) {
        cout << total_score;
    } cout << endl << endl;
}
