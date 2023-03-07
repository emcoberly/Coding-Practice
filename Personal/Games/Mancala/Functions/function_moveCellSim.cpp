#include "../function.h"

void moveCellSim(Cell cell_list[], Cell played_cell, Cell &player1, bool &go_again, bool game_over) {
    // DECLARE ALL NEEDED TEMP VARIABLES
    int played_cell_stones = played_cell.stones;
    go_again = false;
    int curr_cell = played_cell.id;
    bool on_same_side = false;
    bool cascade_flag = false;
    Cell cascade_cell;

    // ITERATE THROUGH STONES ON TURN
    for (int i = 0; i < played_cell_stones; i++) {
        if (curr_cell == 6) {
            player1.stones++;
            if (played_cell_stones - i == 1) {
                go_again = true;
                break;
            }
            played_cell_stones--;
        }
        curr_cell = (curr_cell % 12) + 1;
        cell_list[curr_cell - 1].stones++;

        // DETERMINE FATE OF LAST STONE
        if ((played_cell_stones - i == 1)) {
            if (cell_list[curr_cell - 1].stones > 1) {
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
        player_sum += cell_list[i].stones;
    }
    game_over = player_sum == 0;
    
    if (cascade_flag && !game_over) {
        moveCellSim(cell_list, cascade_cell, player1, go_again, game_over);
    }

    cout << "Cell " << played_cell.id << " was played." << endl;
}
