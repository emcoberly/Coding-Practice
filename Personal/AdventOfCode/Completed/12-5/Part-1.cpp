#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>

using namespace std;

int main() {
    ifstream fin;
    string line;
    vector<int> row1(0), row2(0), row3(0), row4(0), row5(0), row6(0), row7(0), row8(0), row9(0);
    vector<int> count(0), from(0), to(0);
    int num1, num2, num3;
    string junk;
    fin.open("crates.txt");
    if (!fin.is_open()) {
        cerr << "ERROR! Could not open crates.txt." << endl;
    } else {
        while (getline(fin, line)) {
            stringstream parse_line(line);
            parse_line >> junk;
            parse_line >> num1;
            count.push_back(num1);
            parse_line >> junk;
            parse_line >> num2;
            from.push_back(num2);
            parse_line >> junk;
            parse_line >> num3;
            to.push_back(num3);
        }
    }
    fin.close();

    //                     [L]     [H] [W]
    //                 [J] [Z] [J] [Q] [Q]
    // [S]             [M] [C] [T] [F] [B]
    // [P]     [H]     [B] [D] [G] [B] [P]
    // [W]     [L] [D] [D] [J] [W] [T] [C]
    // [N] [T] [R] [T] [T] [T] [M] [M] [G]
    // [J] [S] [Q] [S] [Z] [W] [P] [G] [D]
    // [Z] [G] [V] [V] [Q] [M] [L] [N] [R]
    //  1   2   3   4   5   6   7   8   9 

    vector<char> stack1 = {'Z','J','N','W','P','S'};
    vector<char> stack2 = {'G','S','T'};
    vector<char> stack3 = {'V','Q','R','L','H'};
    vector<char> stack4 = {'V','S','T','D'};
    vector<char> stack5 = {'Q','Z','T','D','B','M','J'};
    vector<char> stack6 = {'M','W','T','J','D','C','Z','L'};
    vector<char> stack7 = {'L','P','M','W','G','T','J'};
    vector<char> stack8 = {'N','G','M','T','B','F','Q','H'};
    vector<char> stack9 = {'R','D','G','C','P','B','Q','W'};
    vector<vector<char>> stacks = {stack1, stack2, stack3, stack4, stack5, stack6, stack7, stack8, stack9};
    vector<char> from_stack;
    vector<char> to_stack;
    for (int i = 0; i < count.size(); i++) {
        for (int j = 0; j < count.at(i); j++) {
            from_stack = stacks.at(from.at(i) - 1);
            to_stack = stacks.at(to.at(i) - 1);
            to_stack.push_back(from_stack.back());
            from_stack.pop_back();
            // cout << from.at(i) - 1 << " " << to.at(i) - 1 << endl;
            stacks.at(from.at(i) - 1) = from_stack;
            stacks.at(to.at(i) - 1) = to_stack;
        }
    }
    for (int i = 0; i < stacks.size(); i++) {
        for (int j = 0; j < stacks.at(i).size(); j++) {
            cout << stacks.at(i).at(j) << " ";
        } cout << endl;
    } cout << endl;

    return 0;
}
