#include "../function.h"

void moveCell(Cell cell_list[], Cell played_cell, int player_id, Cell &player1, Cell &player2, bool &game_over, string game_mode) {
    // DECLARE ALL NEEDED TEMP VARIABLES
    int played_cell_stones = played_cell.stones;
    bool go_again = false;
    int curr_cell = played_cell.id;
    bool on_same_side = false;
    bool cascade_flag = false;
    Cell cascade_cell;

    // ITERATE THROUGH STONES ON TURN
    for (int i = 0; i < played_cell_stones; i++) {
        if ((curr_cell % 6 == 0) && (curr_cell == (6 * player_id))) {
            if (player_id == 1) {
                player1.stones++;
            } else {
                player2.stones++;
            }
            if (played_cell_stones - i == 1) {
                go_again = true;
                break;
            }
            played_cell_stones--;
        }
        curr_cell = (curr_cell % 12) + 1;
        cell_list[curr_cell - 1].stones++;
        on_same_side = (curr_cell >= 1 + (player_id - 1) * 6) && (curr_cell <= 6 + (player_id - 1) * 6);

        // DETERMINE FATE OF LAST STONE
        if ((played_cell_stones - i == 1)) {
            if ((on_same_side) && (game_mode == "Capture") && (cell_list[curr_cell - 1].stones == 1)) {
                // TURN ENDS IN AN EMPTY CELL ON THE PLAYER'S SIDE, POTENTIALLY CAUSING A CAPTURE IN "CAPTURE MODE"
                captureCell(cell_list, cell_list[curr_cell - 1], player_id, player1, player2);
            } else if (game_mode == "Cascade" && (cell_list[curr_cell - 1].stones > 1)) {
                // TURN ENDS IN A NON-EMPTY CELL, CAUSING A CASCADE IN "CASCADE MODE"
                cascade_flag = true;
                cascade_cell = cell_list[curr_cell - 1];
            }
        }
    }

    cell_list[played_cell.id - 1].stones = 0;

    // CHECK IF GAME IS OVER
    int player_sum = 0;
    for (int i = 0; i < 6; i++) {
        player_sum += cell_list[i + (6 * (player_id - 1))].stones;
    }
    game_over = player_sum == 0;
    
    if ((game_mode == "Cascade") && cascade_flag && !game_over) {
        moveCell(cell_list, cascade_cell, player_id, player1, player2, game_over, game_mode);
    }

    if (go_again && !game_over) {
        if ((game_mode == "Cascade") && cascade_flag) {
            cout << "--------------| CASCADED |--------------" << endl;
        }
        buildGameBoard(cell_list, player1, player2);
        moveCell(cell_list, chooseCell(cell_list, player_id), player_id, player1, player2, game_over, game_mode);
    }
}
