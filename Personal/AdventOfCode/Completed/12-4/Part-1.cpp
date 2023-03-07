#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>

using namespace std;

char getIntersection(vector<char> vec1, vector<char> vec2);

int main() {
    ifstream fin;
    string line;
    int p1n1, p1n2, p2n1, p2n2;
    char junk;
    vector<int> p1start(0), p1end(0), p2start(0), p2end(0);
    fin.open("pairs.txt");
    if (!fin.is_open()) {
        cerr << "ERROR! Could not open rucksacks.txt." << endl;
    } else {
        while (getline(fin, line)) {
            stringstream parse_line(line);
            parse_line >> p1n1;
            p1start.push_back(p1n1);
            parse_line >> junk;
            parse_line >> p1n2;
            p1end.push_back(p1n2);
            parse_line >> junk;
            parse_line >> p2n1;
            p2start.push_back(p2n1);
            parse_line >> junk;
            parse_line >> p2n2;
            p2end.push_back(p2n2);
        }
    }
    fin.close();

    bool contains = false;
    int contain_counter = 0;
    for (int i = 0; i < p1start.size(); i++) {
        contains = (
            (
                (p1start.at(i) >= p2start.at(i)) &&
                (p1end.at(i) <= p2end.at(i))
            ) ||
            (
                (p1start.at(i) <= p2start.at(i)) &&
                (p1end.at(i) >= p2end.at(i))
            )
        );
        if (contains) {
            contain_counter++;
            cout << p1start.at(i) << "-" << p1end.at(i) << "," << p2start.at(i) << "-" << p2end.at(i) << endl;
        }
    }

    cout << "Contained pairs: " << contain_counter << endl;

    return 0;
}