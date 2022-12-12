#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>

using namespace std;

int main() {
    ifstream fin;
    fin.open("RPS.txt");
    string line;
    vector<char> opponent(0), me(0);
    if (!fin.is_open()) {
        cerr << "ERROR: No save file exists." << endl;
    } else {
        while (getline(fin, line)) {
            opponent.push_back(line.at(0));
            me.push_back(line.at(2));
        }
    }
    fin.close();

    bool win = false;
    bool draw = false;
    int my_score = 0;
    for (int i = 0; i < me.size(); i++) {
        win = (
            (opponent.at(i) == 'A' && me.at(i) == 'Y') ||
            (opponent.at(i) == 'B' && me.at(i) == 'Z') ||
            (opponent.at(i) == 'C' && me.at(i) == 'X') 
        );
        draw = (
            (opponent.at(i) == 'A' && me.at(i) == 'X') ||
            (opponent.at(i) == 'B' && me.at(i) == 'Y') ||
            (opponent.at(i) == 'C' && me.at(i) == 'Z')
        );
        if (win) {
            my_score += 6;
        } else if (draw) {
            my_score += 3;
        }
        switch(me.at(i)) {
            case 'X':
                my_score += 1;
                break;
            case 'Y':
                my_score += 2;
                break;
            case 'Z':
                my_score += 3;
                break;
            default:
                break;
        }
    }

    cout << "My score: " << my_score << endl;

    return 0;
}