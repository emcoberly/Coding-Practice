#include "../function.h"

void captureCell(Cell cell_list[], Cell captured_cell, int player_id, Cell &player1, Cell &player2) {
    int capture_sum = captured_cell.stones + cell_list[12-captured_cell.id].stones;

    // DON'T ACTUALLY CAPTURE IF THE CELL IS EMPTY
    if (capture_sum == 1) {
        return;
    }

    cell_list[captured_cell.id - 1].stones = 0;
    cell_list[12-captured_cell.id].stones = 0;
    if (player_id == 1) {
        player1.stones += capture_sum;
    } else {
        player2.stones += capture_sum;
    }
    cout << "--------------| CAPTURED |--------------" << endl;
}