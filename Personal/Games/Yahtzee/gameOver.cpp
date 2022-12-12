#include "Yahtzee.h"

bool gameOver(map<string,int> scores_list) {
    for (const auto& kv : scores_list) {
        if (kv.second == -1) {
            return false;
        }
    }
    return true;
}