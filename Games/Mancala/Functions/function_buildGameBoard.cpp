#include "../function.h"

void buildGameBoard(Cell cell_list[], Cell player1, Cell player2) {
    bool middle_row_shift = player2.stones >= 10;
    cout << setw(8) << "12" << setw(5) << "11" << setw(5) << "10" << setw(5) << "9" << setw(5) << "8" << setw(5) << "7" << endl;
    cout << "+——————————————————————————————————————+" << endl;
    cout << "| " << setw(6) << cell_list[11].stones << setw(5) << cell_list[10].stones << setw(5) << cell_list[9].stones << setw(5) << cell_list[8].stones << setw(5) << cell_list[7].stones << setw(5) << cell_list[6].stones << setw(7) << "|" << endl;
    // cout << "|                                             |" << endl;
    cout << "|  " << player2.stones << setw(33 - middle_row_shift) << player1.stones << setw(3) << "|" << endl;
    // cout << "|                                             |" << endl;
    cout << "| " << setw(6) << cell_list[0].stones << setw(5) << cell_list[1].stones << setw(5) << cell_list[2].stones << setw(5) << cell_list[3].stones << setw(5) << cell_list[4].stones << setw(5) << cell_list[5].stones << setw(7) << "|" << endl;
    cout << "+——————————————————————————————————————+" << endl;
    cout << setw(8) << "1" << setw(5) << "2" << setw(5) << "3" << setw(5) << "4" << setw(5) << "5" << setw(5) << "6" << endl;
    cout << endl;
}
