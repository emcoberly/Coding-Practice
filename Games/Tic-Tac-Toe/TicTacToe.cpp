#include <iostream>
#include <random>
#include <ctime>
#include <vector>
using namespace std;

bool CheckXO(char validChoice);
bool CheckMove(int validMove);
void GameBoardCells(int move, char type, vector<char> &cells);
void BuildGameBoard(vector<char> cells);

int main() {

    // Declare variables
    bool noVictory = true;
    bool validXO, validMove;
    char playerChar;
    int turnsTaken = 0, playerMove;
    vector<char> cellCharacters = {' ',' ',' ',' ',' ',' ',' ',' ',' '};

    // Introduction
    cout << "Welcome to Tic-Tac-Toe!" << endl;
    cout << "To pick a place to play, you must enter an integer from 1-9 from this grid format:" << endl;
    cout << "1 2 3\n4 5 6\n7 8 9" << endl;
    cout << "You may enter 'Q' before a game if you would like to quit." << endl;
    cout << "However, you may not quit in the middle of a game." << endl;
    cout << "Without further ado, let's see if you can beat me!" << endl;

    // User chooses 'X' or 'O' (or quits with 'Q')
    cout << "Would you like to be X or O? -> ";
    cin >> playerChar;
    do {
        validXO = CheckXO(playerChar);
        if (!validXO) {
            cout << "That is not a valid option.\nPlease enter 'X', 'O', or 'Q'. -> ";
            cin >> playerChar;
        }
    } while (!validXO);

    if (playerChar == 'Q') {
        return 0;
    }

    BuildGameBoard(cellCharacters);
    
    do {
        // if (playerChar == 'O') {
        //     cout << "Computer's turn:" << endl;
        // }

        cout << "Where would you like to go? -> ";
        cin >> playerMove;
        do {
            validMove = CheckMove(playerMove);
            if (!validMove) {
                cout << "That is not in the specified range.\nPlease enter an integer from 1-9. -> ";
                cin >> playerMove;
            }
        } while (!validMove);

        GameBoardCells(playerMove, playerChar, cellCharacters);
        BuildGameBoard(cellCharacters);

        turnsTaken += 1;
    } while(turnsTaken < 9 && noVictory);

    return 0;
}

// Verifies that User chose a valid option
bool CheckXO(char validChoice) {
    if (validChoice == 'X' || validChoice == 'O' || validChoice == 'Q') {
        return true;
    } else {
        return false;
    }
}

// Verifies that User chose a cell in the game board
bool CheckMove(int validMove) {
    if (validMove >= 1 && validMove <= 9) {
        return true;
    } else {
        return false;
    }
}

// Alters vector of cells
void GameBoardCells(int move, char type, vector<char> &cells) {
    while (cells.at(move - 1) != ' ') {
        cout << "That space is already taken.\nPlease choose an empty space. -> ";
        cin >> move;
        CheckMove(move);
    }
    cells.at(move - 1) = type;
}

// Displays game board
void BuildGameBoard(vector<char> cells) {
    cout << " " << cells.at(0) << " | " << cells.at(1) << " | " << cells.at(2) << endl;
    cout << "---|---|---" << endl;
    cout << " " << cells.at(3) << " | " << cells.at(4) << " | " << cells.at(5) << endl;
    cout << "---|---|---" << endl;
    cout << " " << cells.at(6) << " | " << cells.at(7) << " | " << cells.at(8) << endl;
}