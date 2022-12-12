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

    int my_score = 0;
    for (int i = 0; i < me.size(); i++) {
        switch(me.at(i)) {
            case 'X':
                switch(opponent.at(i)) {
                    case 'A':
                        my_score += 3;
                        break;
                    case 'B':
                        my_score += 1;
                        break;
                    case 'C':
                        my_score += 2;
                        break;
                    default:
                        break;
                }
                break;
            case 'Y':
                my_score += 3;
                switch(opponent.at(i)) {
                    case 'A':
                        my_score += 1;
                        break;
                    case 'B':
                        my_score += 2;
                        break;
                    case 'C':
                        my_score += 3;
                        break;
                    default:
                        break;
                }
                break; 
            case 'Z':
                my_score += 6;
                switch(opponent.at(i)) {
                    case 'A':
                        my_score += 2;
                        break;
                    case 'B':
                        my_score += 3;
                        break;
                    case 'C':
                        my_score += 1;
                        break;
                    default:
                        break;
                }
                break; 
            default:
                break;
        }
    }

    cout << "My score: " << my_score << endl;

    return 0;
}
