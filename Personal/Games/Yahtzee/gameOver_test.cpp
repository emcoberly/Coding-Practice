#include "Yahtzee.h"
#include "gameOver.cpp"

int main() {
  map<string, int> not_over = {{"Aces", 3},
                               {"Deuces", -1},
                               {"Threes", -1},
                               {"Fours", 12},
                               {"Fives", -1},
                               {"Sixes", 24},
                               {"Three-of-a-Kind", 23},
                               {"Four-of-a-Kind", -1},
                               {"Full-House", 25},
                               {"Small-Straight", 30},
                               {"Large-Straight", 40},
                               {"Yahtzee", -1},
                               {"Yahtzee Bonus", 0},
                               {"Chance", 19}};
  map<string, int> over = {{"Aces", 3},
                           {"Deuces", 8},
                           {"Threes", 6},
                           {"Fours", 12},
                           {"Fives", 15},
                           {"Sixes", 24},
                           {"Three-of-a-Kind", 23},
                           {"Four-of-a-Kind", 0},
                           {"Full-House", 25},
                           {"Small-Straight", 30},
                           {"Large-Straight", 40},
                           {"Yahtzee", 0},
                           {"Yahtzee Bonus", 0},
                           {"Chance", 19}};

  cout << "Game is over:\t";
  switch (gameOver(not_over)) {
  case 0:
    cout << "False";
    break;
  case 1:
    cout << "True";
    break;
  default:
    cout << "Error";
    break;
  }
  cout << endl;
  cout << "Game is over:\t";
  switch (gameOver(over)) {
  case 0:
    cout << "False";
    break;
  case 1:
    cout << "True";
    break;
  default:
    cout << "Error";
    break;
  }
  cout << endl;

  return 0;
}
