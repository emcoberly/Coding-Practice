#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

char getIntersection(vector<char> vec1, vector<char> vec2);

int main() {
    ifstream fin;
    string line;
    fin.open("rucksacks.txt");
    vector<char> comp1(0), comp2(0);
    vector<vector<char>> comp1_vec(0), comp2_vec(0);
    if (!fin.is_open()) {
        cerr << "ERROR! Could not open rucksacks.txt." << endl;
    } else {
        while (getline(fin, line)) {
            comp1 = {};
            comp2 = {};
            for (int i = 0; i < line.size() / 2; i++) {
                comp1.push_back(line.at(i));
            }
            comp1_vec.push_back(comp1);
            for (int j = line.size() / 2; j < line.size(); j++) {
                comp2.push_back(line.at(j));
            }
            comp2_vec.push_back(comp2);

        }
    }
    fin.close();
    vector<char> priorities(0);
    int priority_sum = 0;
    for (int k = 0; k < comp1_vec.size(); k++) {
        priorities.push_back(getIntersection(comp1_vec.at(k), comp2_vec.at(k)));
        if (priorities.at(k) >= 65 && priorities.at(k) <= 90) {
            priority_sum += (priorities.at(k) - 38);
        } else {
            priority_sum += (priorities.at(k) - 96);
        }
    }
    cout << getIntersection(comp1_vec.at(0), comp2_vec.at(0)) << endl;
    cout << priorities.size() << endl;
    cout << "Priority sum is: " << priority_sum << endl;

    return 0;
}

char getIntersection(vector<char> vec1, vector<char> vec2) {
    for (int i = 0; i < vec1.size(); i++) {
        for (int j = 0; j < vec2.size(); j++) {
            if (vec1.at(i) == vec2.at(j)) {
                return vec1.at(i);
            }
        }
    }
    return '!';
}
