#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <cmath>

using namespace std;

class Monkey {
    public:
        int id;
        vector<long long int> items;
        long long int newValue(int id, long long int oldValue);
        int test_divisor;
        int true_id;
        int false_id;
        long int inspected = 0;
};

long long int Monkey::newValue(int id, long long int oldValue) {
    if (id == 0) {
        return oldValue * 19;
    } else if (id == 1) {
        return oldValue + 6;
    } else if (id == 2) {
        return oldValue * oldValue;
    } else if (id == 3) {
        return oldValue + 3;
    }
    return 0;
}

int main() {

    Monkey m0;
    m0.items = {79, 98};
    m0.test_divisor = 23;
    m0.true_id = 2;
    m0.false_id = 3;
    m0.id = 0;

    Monkey m1;
    m1.items = {54, 65, 75, 74};
    m1.test_divisor = 19;
    m1.true_id = 2;
    m1.false_id = 0;
    m1.id = 1;

    Monkey m2;
    m2.items = {79, 60, 97};
    m2.test_divisor = 13;
    m2.true_id = 1;
    m2.false_id = 3;
    m2.id = 2;

    Monkey m3;
    m3.items = {74};
    m3.test_divisor = 17;
    m3.true_id = 0;
    m3.false_id = 1;
    m3.id = 3;

    vector<Monkey> monkeys = {m0, m1, m2, m3};
    long long int tempVal;
    bool divisible;
    long int tempRange;
    int modulo = 23 * 13 * 17 * 19;

    for (int i = 0; i < 10000; i++) {
        for (int j = 0; j < monkeys.size(); j++) {
            tempRange = monkeys.at(j).items.size();
            for (int k = 0; k < tempRange; k++) {
                tempVal = monkeys.at(j).items.at(k);
                tempVal = monkeys.at(j).newValue(monkeys.at(j).id, monkeys.at(j).items.at(k));
                tempVal = tempVal % modulo;
                divisible = tempVal % monkeys.at(j).test_divisor == 0;
                if (divisible) {
                    monkeys.at(monkeys.at(j).true_id).items.push_back(tempVal);
                } else {
                    monkeys.at(monkeys.at(j).false_id).items.push_back(tempVal);
                }
                monkeys.at(j).inspected++;
                // cout << monkeys.at(j).id << ": " << monkeys.at(j).items.size() << endl;
            }
            for (int l = 0; l < tempRange; l++) {
                monkeys.at(j).items.erase(monkeys.at(j).items.begin());
            }
        }
    }

    for (int i = 0; i < monkeys.size(); i++) {
        cout << "Monkey " << monkeys.at(i).id << ": " << monkeys.at(i).inspected << endl;
    }
    
    return 0;
}
