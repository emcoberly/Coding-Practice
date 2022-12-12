#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>

using namespace std;

string moveSprite(string string, int center);

int main() {
    ifstream fin;
    string line;

    int regX = 1;
    int cycles = 0;
    int position;

    string cycle;
    int input;

    vector<string> rows(0);
    string totalString = "========================================";
    string currString = "###.....................................";

    fin.open("signal.txt");
    if (!fin.is_open()) {
        cerr << "ERROR! Could not open tree.txt." << endl;
    } else {
        while (getline(fin, line)) {
            stringstream parseline(line);
            parseline >> cycle;
            position = cycles % 40;
            // cout << totalString << endl;
            cout << currString << endl;
            if (cycle == "noop") {
                totalString.at(position) = currString.at(position);
                cycles++;
            } else {
                parseline >> input;
                // cout << " " << input;
                totalString.at(position) = currString.at(position);
                cycles++;
                position = cycles % 40;
                if (cycles % 40 == 0) {
                    rows.push_back(totalString);
                    totalString = "========================================";
                }
                // cout << totalString << endl;
                cout << currString << endl;
                totalString.at(position) = currString.at(position);
                cycles++;
                regX = regX + input;
                if (regX < 0) {
                    regX = 40 + regX;
                } else if (regX >= 40) {
                    regX = regX % 40;
                }
                currString = moveSprite(currString, regX);
                // cout << currString << endl;
            }
            if (cycles % 40 == 0) {
                rows.push_back(totalString);
                totalString = "========================================";
            }
        }
    }
    fin.close();

    for (int i = 0; i < rows.size(); i++) {
        cout << rows.at(i) << endl;
    }

    return 0;
}

string moveSprite(string string, int center) {
    for (int i = 0; i < string.size(); i++) {
        if (string.at(i) == '#') {
            string.at(i) = '.';
        }
    }
    string.at(center) = '#';
    if (center == 0) {
        string.at(39) = '#';
    } else {
        string.at(center - 1) = '#';
    }
    if (center == 39) {
        string.at(0) = '#';
    } else {
        string.at(center + 1) = '#';
    }
    
    return string;
}
