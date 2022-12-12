#pragma once

#include <string>
#include <iostream>
#include <iomanip>
#include <vector>

#include "./Classes/class_cell.cpp"

using namespace std;

string welcomePlayers();
void initializeBoard(Cell cell_list[]);
void buildGameBoard(Cell cell_list[], Cell player1, Cell player2);
Cell chooseCell(Cell cell_list[], int player_id);
void moveCell(Cell cell_list[], Cell played_cell, int player_id, Cell &player1, Cell &player2, bool &game_over, string game_mode);
void moveCellSim(Cell cell_list[], Cell played_cell, Cell &player1, bool &go_again, bool game_over);
void captureCell(Cell cell_list[], Cell captured_cell, int player_id, Cell &player1, Cell &player2);
