#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>

using namespace std;

int main() {
    ifstream fin;
    fin.open("elves.txt");
    string line;
    int number;
    vector<vector<int>> vec_of_vectors(0);
    vector<int> elf_vector(0);
    if (!fin.is_open()) {
        cerr << "ERROR: No save file exists." << endl;
    } else {
        while (getline(fin, line)) {
            stringstream int_line(line);
            if (line == "") {
                vec_of_vectors.push_back(elf_vector);
                elf_vector = {};
            } else {
                int_line >> number;
                elf_vector.push_back(number);
            }
        }
    }
    fin.close();
    vector<int> sums(0);
    int sum;
    int maxSum = 0;
    for (int i = 0; i < vec_of_vectors.size(); i++) {
        sum = 0;
        for (int j = 0; j < vec_of_vectors.at(i).size(); j++) {
            sum += vec_of_vectors.at(i).at(j);
        }
        sums.push_back(sum);
        if (sum > maxSum) {
            maxSum = sum;
        }
    } cout << endl << "Max sum is: " << maxSum << endl;
    int max1 = maxSum, max2, max3;
    int minDiff = 100000;
    for (int k = 0; k < sums.size(); k++) {
        if (((max1 - sums.at(k)) < minDiff) && ((max1 - sums.at(k)) > 0)) {
            max2 = sums.at(k);
            minDiff = max1 - sums.at(k);
        }
    }
    minDiff = 100000;
    for (int l = 0; l < sums.size(); l++) {
        if (((max2 - sums.at(l)) < minDiff) && ((max2 - sums.at(l)) > 0)) {
            max3 = sums.at(l);
            minDiff = max2 - sums.at(l);
        }
    }
    cout << "Maxes 1, 2, 3: " << max1 << ", " << max2 << ", " << max3 << endl;
    cout << "Sum: " << max1 + max2 + max3 << endl;

    return 0;
}
