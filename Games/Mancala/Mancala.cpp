#include "function.h"

#include "Functions/function_buildGameBoard.cpp"
#include "Functions/function_captureCell.cpp"
#include "Functions/function_chooseCell.cpp"
#include "Functions/function_initializeBoard.cpp"
#include "Functions/function_moveCell.cpp"
#include "Functions/function_welcomePlayers.cpp"

int main() {

    // CHOOSE GAME MODE
    string game_mode = welcomePlayers();

    // INITIALIZE THE TWO PLAYERS
    Cell player1;
    player1.id = 1;
    player1.stones = 0;
    Cell player2;
    player2.id = 2;
    player2.stones = 0;

    // CREATE THE BOARD
    Cell board_cells[12];
    initializeBoard(board_cells);
    buildGameBoard(board_cells, player1, player2);

    // TAKE TURNS
    bool game_over = false;
    Cell played_cell;
    int player_id = 1;
    while (!game_over) {
        played_cell = chooseCell(board_cells, player_id);
        cout << "Cell " << played_cell.id << " was played." << endl;
        moveCell(board_cells, played_cell, player_id, player1, player2, game_over, game_mode);
        buildGameBoard(board_cells, player1, player2);
        player_id = player_id % 2 + 1;
    }

    // GAME FINISHES
    if (player1.stones == player2.stones) {
        cout << "It's a tie!" << endl;
    } else {
        cout << "Player " << (player2.stones > player1.stones) + 1 << " wins!" << endl;
    }

    return 0;
}
