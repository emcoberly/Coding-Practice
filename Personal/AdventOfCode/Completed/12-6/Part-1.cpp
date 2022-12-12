#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>

using namespace std;

bool contains(string my_string);

int main() {
    ifstream fin;
    string line;
    fin.open("buffer.txt");
    string my_string;
    bool same4 = false;
    int counter = 0;
    if (!fin.is_open()) {
        cerr << "ERROR! Could not open buffe.txt." << endl;
    } else {
        while (getline(fin, line)) {
            my_string = line;
        }
    }
    fin.close();

    string temp_string = "";
    for (int i = 0; i < my_string.size() - 3; i++) {
        for (int j = 0; j < 4; j++) {
            temp_string += my_string.at(i + j);
        }
        counter = i;
        // cout << counter << endl;
        cout << temp_string << endl;
        if (!contains(temp_string)) {
            break;
        }
        temp_string = "";
    }

    cout << "Counter: " << counter + 4 << endl;
    
    return(0);
}

bool contains(string my_string) {
    for (int i = 0; i < my_string.size(); i++) {
        for (int j = i + 1; j < my_string.size(); j++) {
            if (my_string.at(i) == my_string.at(j)) {
                cout << my_string.at(i) << my_string.at(j) << endl;
                return true;
            }
        }
    }
    return false;
}
