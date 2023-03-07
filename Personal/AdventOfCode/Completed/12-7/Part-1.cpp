#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>

using namespace std;

class Dir {
    public:
    string name = "";
    long int size = 0;
};

bool contains(string string1, string string2);

int main() {

    char cmd;
    string instruction, name, dest;
    string junk;
    long int size;
    bool ls = false;
    bool cd = false;

    vector<Dir> directories(0);
    Dir currDir, tempDir;
    currDir.name = "/";
    tempDir.name = currDir.name;
    directories.push_back(currDir);

    ifstream fin;
    string line;
    fin.open("directory.txt");
    if (!fin.is_open()) {
        cerr << "ERROR! Could not open directory.txt." << endl;
    } else {
        while (getline(fin, line)) {
            stringstream parseline(line);
            if (ls) {
                if (line.at(0) != '$' && line.at(0) != 'e') {
                    if (isdigit(line.at(0))) {
                        parseline >> size >> junk;
                        currDir.size += size;
                    } else {
                        parseline >> junk >> name;
                        tempDir.name = currDir.name;
                        tempDir.size = 0;
                        tempDir.name += name;
                        tempDir.name += '/';
                        directories.push_back(tempDir);
                        tempDir = currDir;
                    }
                }
            }
            if (line.at(0) == '$' || line.at(0) == 'e') {
                if (ls) {
                    ls = false;
                    for (int i = 0; i < directories.size(); i++) {
                        if (directories.at(i).name == currDir.name) {
                            directories.at(i).size = currDir.size;
                            currDir.size = 0;
                        }
                    }
                }
                if (line.at(0) != 'e') {
                    parseline >> cmd >> instruction;
                    if (instruction == "ls") {
                        ls = true;
                    } else if (instruction == "cd") {
                        parseline >> dest;
                        if (dest == "..") {
                            currDir.name.pop_back();
                            while (currDir.name.back() != '/') {
                                currDir.name.pop_back();
                            }
                        } else {
                            currDir.name += dest;
                            currDir.name += '/';
                        }
                    }
                }
            }
        }
    }
    fin.close();

    // for (int i = 0; i < directories.size(); i++) {
    //     cout << directories.at(i).name << ": " << directories.at(i).size << endl;
    // }

    for (int j = directories.size() - 1; j > 0; j--) {
        for (int k = j - 1; k >= 0; k--) {
            if (contains(directories.at(j).name, directories.at(k).name) && directories.at(j).name != directories.at(k).name) {
                directories.at(k).size += directories.at(j).size;
                // cout << directories.at(j).name << ": " << directories.at(j).size << endl;
                // cout << directories.at(k).name << ": " << directories.at(k).size << endl << endl;
                break;
            }
        }
    }

    // cout << contains("beans", "beanstalk") << contains("timeshare", "time") << contains("category", "caterpillar") << endl;

    long int sum = 0;
    for (int l = 0; l < directories.size(); l++) {
        if (directories.at(l).size <= 100000) {
            cout << directories.at(l).name << ": " << directories.at(l).size << endl;
            sum += directories.at(l).size;
        }
    }

    cout << "Sum: " << sum << endl;

    return 0;
}

bool contains(string string1, string string2) {
    if (string1.size() <= string2.size()) {
        for (int i = 0; i < string1.size(); i++) {
            if (string1.at(i) != string2.at(i)) {
                return false;
            }
        }
    } else if (string1.size() > string2.size()) {
        for (int i = 0; i < string2.size(); i++) {
            if (string1.at(i) != string2.at(i)) {
                return false;
            }
        }
    }
    return true;
}
