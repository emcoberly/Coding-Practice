#include "Yahtzee.h"
#include "displayDice.cpp"
#include "gameOver.cpp"
#include "rollDice.cpp"
#include "saveDice.cpp"
#include "saveScore.cpp"
#include "scoreboard.cpp"
#include "sumDice.cpp"

int main() {

  // SET RANDOM SEED
  srand(time(0));

  // SET UP SCOREBOARD
  map<string, int> scores = {
      {"Aces", -1},       {"Deuces", -1},          {"Threes", -1},
      {"Fours", -1},      {"Fives", -1},           {"Sixes", -1},
      {"Bonus", -1},      {"Three-of-a-Kind", -1}, {"Four-of-a-Kind", -1},
      {"Full-House", -1}, {"Small-Straight", -1},  {"Large-Straight", -1},
      {"Yahtzee", -1},    {"Yahtzee Bonus", 0},    {"Chance", -1}};

  // PLAY UNTIL GAME IS OVER
  while (!gameOver(scores)) {
    vector<int> my_dice = {0, 0, 0, 0, 0};

    // ROLL UP TO 3 TIMES
    for (int roll = 1; roll <= 3; roll++) {

      // VARIABLES
      string input;
      bool invalid_input = true;
      bool turn_finished = false;

      my_dice = rollDice(my_dice);
      displayDice(my_dice);
      scoreboard(scores);
      if (roll < 3) {
        vector<int> temp_roll = my_dice;
        cout << "Would you like to roll again or take your score now?" << endl;
        while ((my_dice == temp_roll) && !turn_finished) {
          cout << "(roll/score) -> ";
          cin >> input;
          if ((input != "roll") && (input != "score")) {
            cout << "Invalid input. Please try again." << endl;
            cin.clear();
            cin.ignore(1000, '\n');
          }
          if (input == "roll") {
            saveDice(my_dice);
          } else if (input == "score") {
            saveScore(my_dice, scores, roll, turn_finished);
          }
        }
      } else {
        saveScore(my_dice, scores, roll, turn_finished);
      }
      if (turn_finished) {
        break;
      }
    }
  }

  return 0;
}
