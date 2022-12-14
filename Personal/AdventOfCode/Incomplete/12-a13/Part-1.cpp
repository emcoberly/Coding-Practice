#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>

using namespace std;

class Package {
    public:
    int level;
    int value = -1;
};

int main() {

    /* YOUR CODE GOES HERE*/
    vector<string> packages1(0);
    vector<string> packages2(0);

    vector<Package> packvec1(0);
    vector<Package> packvec2(0);

    int level = 0;
    Package currPackage;
    int line_num = 1;

    ifstream fin;
    string line;
    fin.open("text.txt");
    if (!fin.is_open()) {
        cerr << "ERROR! Could not open text.txt." << endl;
    } else {
        while (getline(fin, line)) {

            /* YOUR CODE GOES HERE */
            if (line == "\0") {
                continue;
            }
            if (line_num % 2 == 1) {
                packages1.push_back(line);
            } else {
                packages2.push_back(line);
            }
            line_num++;
        }
    }
    fin.close();

    char inputChar;
    int inputInt;
    for (int i = 0; i < packages1.size(); i++) {
        stringstream parseline(packages1.at(i));
        level = 0;
        for (int j = 0; j < packages1.at(i).size(); j++) {
            if (packages1.at(i).at(j) == '[') {
                parseline >> inputChar;
                // cout << inputChar;
                level++;
                // cout << level << " ";
                if (packages1.at(i).at(j+1) == ']') {
                    parseline >> inputChar;
                    currPackage.level = level;
                    packvec1.push_back(currPackage);
                    currPackage = {};
                    level--;
                    j++;
                }
                // cout << level << endl;
            } else if (isdigit(packages1.at(i).at(j))) {
                parseline >> inputInt;
                // cout << inputInt;
                currPackage.level = level;
                currPackage.value = inputInt;
                packvec1.push_back(currPackage);
                currPackage = {};
                if (inputInt == 10) {
                    j++;
                }
            } else if (packages1.at(i).at(j) == ']') {
                parseline >> inputChar;
                // cout << inputChar;
                level--;
            } else {
                parseline >> inputChar;
                // cout << inputChar;
            }
            parseline.clear();
            parseline.sync();
        }
        // cout << endl;
    }

    for (int i = 0; i < packvec1.size(); i++) {
        cout << packvec1.at(i).value << " " << packvec1.at(i).level << endl;
    }
    
    return 0;
}
