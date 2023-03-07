#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <cmath>

using namespace std;

class Monkey {
    public:
        int id;
        vector<long int> items;
        long int newValue(int id, long int oldValue);
        int test_divisor;
        int true_id;
        int false_id;
        long int inspected = 0;
};

long int Monkey::newValue(int id, long int oldValue) {
    if (id == 0) {
        return oldValue * 11;
    } else if (id == 1) {
        return oldValue + 8;
    } else if (id == 2) {
        return oldValue * 3;
    } else if (id == 3) {
        return oldValue + 4;
    } else if (id == 4) {
        return oldValue * oldValue;
    } else if (id == 5) {
        return oldValue + 2;
    } else if (id == 6) {
        return oldValue + 3;
    } else if (id == 7) {
        return oldValue + 5;
    }
    return 0;
}

int main() {

    Monkey m0;
    m0.items = {77, 69, 76, 77, 50, 58};
    m0.test_divisor = 5;
    m0.true_id = 1;
    m0.false_id = 5;
    m0.id = 0;

    Monkey m1;
    m1.items = {75, 70, 82, 83, 96, 64, 62};
    m1.test_divisor = 17;
    m1.true_id = 5;
    m1.false_id = 6;
    m1.id = 1;

    Monkey m2;
    m2.items = {53};
    m2.test_divisor = 2;
    m2.true_id = 0;
    m2.false_id = 7;
    m2.id = 2;

    Monkey m3;
    m3.items = {85, 64, 93, 64, 99};
    m3.test_divisor = 7;
    m3.true_id = 7;
    m3.false_id = 2;
    m3.id = 3;

    Monkey m4;
    m4.items = {61, 92, 71};
    m4.test_divisor = 3;
    m4.true_id = 2;
    m4.false_id = 3;
    m4.id = 4;

    Monkey m5;
    m5.items = {79, 73, 50, 90};
    m5.test_divisor = 11;
    m5.true_id = 4;
    m5.false_id = 6;
    m5.id = 5;

    Monkey m6;
    m6.items = {50, 89};
    m6.test_divisor = 13;
    m6.true_id = 4;
    m6.false_id = 3;
    m6.id = 6;

    Monkey m7;
    m7.items = {83, 56, 64, 58, 93, 91, 56, 65};
    m7.test_divisor = 19;
    m7.true_id = 1;
    m7.false_id = 0;
    m7.id = 7;

    vector<Monkey> monkeys = {m0, m1, m2, m3, m4, m5, m6, m7};
    long int tempVal;
    bool divisible;
    long int tempRange;

    // src: https://github.com/mebeim/aoc/blob/master/2022/README.md#day-11---monkey-in-the-middle
    // HUGE THANKS to Marco Bonelli @mebeim (Reddit, Github) for explaining
    // the theory behind the second part, used in lines 107, 115, 116
    int modulo = 2*3*5*7*11*13*17*19;

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
            }
            for (int l = 0; l < tempRange; l++) {
                monkeys.at(j).items.erase(monkeys.at(j).items.begin());
            }
        }
    }

    for (int i = 0; i < monkeys.size(); i++) {
        cout << "Monkey " << monkeys.at(i).id << ":" << monkeys.at(i).inspected << endl;
    }
    
    return 0;
}
