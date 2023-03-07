#include <iostream>
#include <random>
#include <vector>
#include <iomanip>

using namespace std;

int main() {
    srand(time(0));
    vector<char> cases(0);
    double a = 0.03, b = 0.08, c = 0.15, d = 0.25, e = 0.5;
    int a_count = 0, b_count = 0, c_count = 0, d_count = 0, e_count = 0;
    double prob_a = 0.0, prob_b = 0.0, prob_c = 0.0, prob_d = 0.0, prob_e = 0.0;
    int letter_choice;
    int iterations = 0;

    cout << "Enter number of simulation iterations: ";
    cin >> iterations;

    for (int i = 0; i < iterations; i++) {
        letter_choice = rand() % 100 + 1;
        if (letter_choice < 3) {
            cases.push_back('A');
        } else if (letter_choice < 10) {
            cases.push_back('B');
        } else if (letter_choice < 25) {
            cases.push_back('C');
        } else if (letter_choice < 50) {
            cases.push_back('D');
        } else if (letter_choice <= 100) {
            cases.push_back('E');
        } else {
            cout << "Pushed invalid value." << endl;
        }
    }
    
    for (int p = 0; p < cases.size(); p++) {
        if (cases.at(p) == 'A') {
            a_count++;
        } else if (cases.at(p) == 'B') {
            b_count++;
        } else if (cases.at(p) == 'C') {
            c_count++;
        } else if (cases.at(p) == 'D') {
            d_count++;
        } else if (cases.at(p) == 'E') {
            e_count++;
        } else {
            cout << "Detected invalid probability." << endl;
        }
    }

    prob_a = static_cast<double>(a_count) / iterations;
    prob_b = static_cast<double>(b_count) / iterations;
    prob_c = static_cast<double>(c_count) / iterations;
    prob_d = static_cast<double>(d_count) / iterations;
    prob_e = static_cast<double>(e_count) / iterations;

    cout << "Defined probability of \'A\': " << fixed << setprecision(4) << a << endl;
    cout << "Expected: " <<  static_cast<int>(a * iterations) << endl;
    cout << "Calculated: " << a_count << " / " << iterations << " = " << fixed << setprecision(4) << prob_a << endl;
    cout << "Error: " << fixed << setprecision(4) << abs((a - prob_a) * 100) << "%" << endl << endl;
    cout << "Defined probability of \'B\': " << fixed << setprecision(4) << b << endl;
    cout << "Expected: " <<  static_cast<int>(b * iterations) << endl;
    cout << "Calculated: " << b_count << " / " << iterations << " = " << fixed << setprecision(4) << prob_b << endl;
    cout << "Error: " << fixed << setprecision(4) << abs((b - prob_b) * 100) << "%" << endl << endl;
    cout << "Defined probability of \'C\': " << fixed << setprecision(4) << c << endl;
    cout << "Expected: " <<  static_cast<int>(c * iterations) << endl;
    cout << "Calculated: " << c_count << " / " << iterations << " = " << fixed << setprecision(4) << prob_c << endl;
    cout << "Error: " << fixed << setprecision(4) << abs((c - prob_c) * 100) << "%" << endl << endl;
    cout << "Defined probability of \'D\': " << fixed << setprecision(4) << d << endl;
    cout << "Expected: " <<  static_cast<int>(d * iterations) << endl;
    cout << "Calculated: " << d_count << " / " << iterations << " = " << fixed << setprecision(4) << prob_d << endl;
    cout << "Error: " << fixed << setprecision(4) << abs((d - prob_d) * 100) << "%" << endl << endl;
    cout << "Defined probability of \'E\': " << fixed << setprecision(4) << e << endl;
    cout << "Expected: " <<  static_cast<int>(e * iterations) << endl;
    cout << "Calculated: " << e_count << " / " << iterations << " = " << fixed << setprecision(4) << prob_e << endl;
    cout << "Error: " << fixed << setprecision(4) << abs((e - prob_e) * 100) << "%" << endl << endl;
}