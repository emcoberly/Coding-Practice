#include "../function.h"

Cell chooseCell(Cell cell_list[], int player_id) {
    bool cell_is_valid = false;
    int cell_id = 0;
    cout << "Choose which cell you would like to move: " << endl;
    do {
        cout << "Player " << player_id << "\'s turn -> ";
        cin >> cell_id;
        if (cin.fail() || (cell_id < 1) || (cell_id > 12)) {
            cin.clear();
            cin.ignore(1000, '\n');
            cout << "Not a valid cell number. Please try again." << endl;
        } else {
            if ((cell_id >= 1 + (player_id - 1) * 6) && (cell_id <= 6 + (player_id - 1) * 6)) {
                if (cell_list[cell_id - 1].stones == 0) {
                    cout << "Please choose a non-empty cell." << endl;
                } else {
                    cell_is_valid = true;
                }
            } else {
                cout << "Please choose a cell from your own side." << endl;
            }
        }
    } while (!cell_is_valid);

    Cell cell_chosen;
    for (int i = 0; i < 12; i++) {
        if (cell_id == (i + 1)) {
            return cell_list[i];
        }
    }

    return cell_chosen;
}
