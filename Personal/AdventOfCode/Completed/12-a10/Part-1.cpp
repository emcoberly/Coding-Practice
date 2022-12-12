#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>

using namespace std;

int main() {
    ifstream fin;
    string line;

    int regX = 1;
    int cycles = 0;
    string cycle;
    int input;
    bool signal_strength;
    int signal;
    vector<int> strengths(0);

    fin.open("signal.txt");
    if (!fin.is_open()) {
        cerr << "ERROR! Could not open tree.txt." << endl;
    } else {
        while (getline(fin, line)) {
            stringstream parseline(line);
            parseline >> cycle;
            signal_strength = cycles % 20 == 0 && cycles % 40 != 0;
            if (signal_strength) {
                strengths.push_back(cycles * regX);
            }
            if (cycle == "noop") {
                cycles++;
            } else {
                parseline >> input;
                cycles++;
                signal_strength = cycles % 20 == 0 && cycles % 40 != 0;
                if (signal_strength) {
                    strengths.push_back(cycles * regX);
                }
                regX += input;
                cycles++;
            }
        }
    }
    fin.close();

    int signal_sum = 0;
    for (int i = 0; i < strengths.size(); i++) {
        signal_sum += strengths.at(i);
    }

    cout << "Total Strength: " << signal_sum << endl;

    return 0;
}
