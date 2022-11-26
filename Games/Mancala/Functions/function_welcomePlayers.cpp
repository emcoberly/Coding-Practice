#include "../function.h"

string welcomePlayers() {
    cout << "Welcome to Mancala!" << endl;
    cout << "Would you like to play Capture or Cascade?" << endl;
    cout << "1) Capture" << endl << "2) Cascade" << endl << "3) Quit" << endl;
    bool valid_input = false;
    int input;
    string game_mode = "";
    do {
        cout << "-> ";
        cin >> input;
        if (cin.fail()) {
            cin.clear();
            cin.ignore(1000, '\n');
            cout << "Input invalid. Please try again." << endl;
        } else {
            if (input == 1) {
                game_mode = "Capture";
                valid_input = true;
            } else if (input == 2) {
                game_mode = "Cascade";
                valid_input = true;
            } else if (input == 3) {
                cout << "Thank you for playing!" << endl;
                return 0;
            } else {
                cout << "Please enter 1 or 2 to select game mode or 3 to quit." << endl;
            }
        }
    } while (!valid_input);
    cout << game_mode << " mode selected." << endl << endl;

    return game_mode;
}
