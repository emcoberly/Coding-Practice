#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

char getIntersection3(string str1, string str2, string str3);

int main() {
    ifstream fin;
    string line;
    fin.open("rucksacks.txt");
    vector<string> set_of_3(0);
    vector<vector<string>> sets_of_3(0);
    if (!fin.is_open()) {
        cerr << "ERROR! Could not open rucksacks.txt." << endl;
    } else {
        while (getline(fin, line)) {
            set_of_3.push_back(line);
            if (set_of_3.size() == 3) {
                sets_of_3.push_back(set_of_3);
                set_of_3 = {};
            }
        }
    }

    vector<char> badges(0);
    int badge_sum = 0;
    for (int i = 0; i < sets_of_3.size(); i++) {
        badges.push_back(getIntersection3(sets_of_3.at(i).at(0), sets_of_3.at(i).at(1), sets_of_3.at(i).at(2)));
        // cout << badges.at(i) << endl;
        if (badges.at(i) >= 65 && badges.at(i) <= 90) {
            badge_sum += (badges.at(i) - 38);
        } else {
            badge_sum += (badges.at(i) - 96);
        }
    }
    cout << "Badge sum is: " << badge_sum << endl;

    return 0;
}

char getIntersection3(string str1, string str2, string str3) {
    for (int i = 0; i < str1.size(); i++) {
        for (int j = 0; j < str2.size(); j++) {
            for (int k = 0; k < str3.size(); k++) {
                if ((str1.at(i) == str2.at(j)) && (str2.at(j) == str3.at(k))) {
                    return str1.at(i);
                }
            }
        }
    }
    return '!';
}
