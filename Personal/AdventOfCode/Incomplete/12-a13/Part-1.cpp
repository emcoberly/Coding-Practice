#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>

using namespace std;

int main() {

    /* YOUR CODE GOES HERE*/

    ifstream fin;
    string line;
    fin.open("text.txt");
    if (!fin.is_open()) {
        cerr << "ERROR! Could not open text.txt." << endl;
    } else {
        while (getline(fin, line)) {

            /* YOUR CODE GOES HERE */

        }
    }
    fin.close();
    
    return 0;
}
