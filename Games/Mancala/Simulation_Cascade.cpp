#include "function.h"

#include "Functions/function_buildGameBoard.cpp"
#include "Functions/function_chooseCell.cpp"
#include "Functions/function_initializeBoard.cpp"
#include "Functions/function_moveCellSim.cpp"

int main() {
    Cell player1;
    player1.id = 1;
    player1.stones = 0;
    Cell player2;
    player2.id = 2;
    player2.stones = 0;

    Cell board_cells[12];

    bool go_again = true;
    bool game_over = false;
    int player_id = 1;
    initializeBoard(board_cells);
    vector<int> play_vector(0);
    moveCellSim(board_cells, board_cells[0], player1, go_again, game_over);
    play_vector.push_back(1);
    while (go_again && !game_over) {
        if (board_cells[5].stones >= 1) {
            moveCellSim(board_cells, board_cells[5], player1, go_again, game_over);
            play_vector.push_back(6);
        } else if (board_cells[4].stones >= 1) {
            moveCellSim(board_cells, board_cells[4], player1, go_again, game_over);
            play_vector.push_back(5);
        } else if (board_cells[3].stones >= 1) {
            moveCellSim(board_cells, board_cells[3], player1, go_again, game_over);
            play_vector.push_back(4);
        } else if (board_cells[2].stones >= 1) {
            moveCellSim(board_cells, board_cells[2], player1, go_again, game_over);
            play_vector.push_back(3);
        } else if (board_cells[1].stones >= 1) {
            moveCellSim(board_cells, board_cells[1], player1, go_again, game_over);
            play_vector.push_back(2);
        } else if (board_cells[0].stones >= 1) {
            moveCellSim(board_cells, board_cells[0], player1, go_again, game_over);
            play_vector.push_back(1);
        }
    }
    buildGameBoard(board_cells, player1, player2);
    for (int i = 0; i < play_vector.size(); i++) {
        cout << play_vector.at(i) << " ";
    } cout << endl;
    cout << player1.stones << endl;

    return 0;
}
