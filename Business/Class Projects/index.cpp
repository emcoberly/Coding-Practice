#include <iostream>
#include <cmath>
#include <string>
#include <sstream>
using namespace std;

int userNum;
bool inRange(unsigned low, unsigned high, unsigned x) {
    return(low <= userNum && userNum <= high);
}

int main() {
    bool passCheck = false;
    while(passCheck==false) {
        cout << "Please enter a number: " << endl;
        cin >> userNum;
        string userStr = to_string(userNum);
        int indexNum = 0;
        while(passCheck==false) {
            cout << userNum << " " << userStr << " " << indexNum << " " << userStr.at(indexNum) << " " << inRange(0 ,9, userStr.at(indexNum)) << endl;
            if(indexNum==userStr.size()) {
                passCheck = true;
            } else if(inRange(0, 9, userStr.at(indexNum))) {
                indexNum += 1;
            } else {
                cout << "That is not a valid number." << endl;
                break;
            }
        }
    }
    cout << "Your number is: " << userNum << endl;

    return 0;

}