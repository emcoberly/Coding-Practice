#include <iostream>
#include <random>
#include <ctime>
#include <vector>

using namespace std;

const int GAMEBOARD_ROWS = 10;
const int GAMEBOARD_COLS = 8;

void Welcome();
void GameMode(char &mode);

void Guesser();
void MasterPegs(vector<char> &master_pegs);
bool CheckColor(string user_guess);
void ComparePegs(vector<char> &correct, vector<char> master, vector<char> guesser);
void BuildGameBoard(char game_board[GAMEBOARD_ROWS][GAMEBOARD_COLS], vector<char> compare_pegs, vector<char> user_guess, int turn);
bool GuesserWin(vector<char> correct);

void Master();
bool CheckJudge(vector<char> judgment);
void ReorderJudge(vector<char> &judgment);
bool VerifyJudge(vector<char> user_judge, vector<char> actual_judge);
void BuildMasterBoard(char game_board[GAMEBOARD_ROWS][GAMEBOARD_COLS], vector<char> master_sequence, vector<char> user_judge, int turn);

// TO DO:
// - FIX JUDGMENT COMPARISON ON GAMEBOARD
// - MAKE AI FOR GUESSER IN MASTER() FUNCTION
// - ENHANCE ERROR CHECKING
// - AI VICTORY MESSAGE
// - AI DEFEAT MESSAGE

int main() {

    Welcome();

    while (true) {
        char mode;
        GameMode(mode);

        // UNDER CONSTRUCTION //
        if (mode == '1') {
            Master();
        // UNDER CONSTRUCTION //

        } else if (mode == '2') {
            Guesser();
        } else {
            cout << "\nThank you for playing!" << endl;
            return 0;
        }
    }
}

void Welcome() {
    cout << "Welcome to MasterMind!\n\nThis game will test your logic as well as your cleverness." << endl;
    cout << "In MasterMind, you can either guess my sequence or make your own." << endl;
    cout << "\nHere are the rules:" << endl;
    cout << "  1. Someone will create a sequence of six colors: red (R), orange (O), yellow (Y), green (G), blue (B), and white (w)." << endl;
    cout << "  2. When you guess, you will enter a sequence of four of these colors, duplicates included." << endl;
    cout << "     When I guess, you will judge my guess by entering \'P\' for every correct color in the correct place" << endl;
    cout << "       and \'C\' for every correct color in the incorrect place." << endl;
    cout << "  3. A player wins when they guess the correct code within 10 turns or if their code is not guessed in 10 turns." << endl;
    cout << "  4. Have fun!" << endl << endl;
}

void GameMode(char &mode) {
    
    cout << "What would you like to do?" << endl;
    cout << "1) Be the Master" << endl;
    cout << "2) Be the Guesser" << endl;
    cout << "3) Quit" << endl;
    cout << "-> ";

    do {
        cin >> mode;
        if (mode != '1' && mode != '2' && mode != '3') {
            cout << "Invalid input! Please try again.\n-> ";
            cin.clear();
            cin.ignore(100,'\n');
        }
    } while (mode != '1' && mode != '2' && mode != '3');
}

void Guesser() {

    cout << "\nI see you wish to be the Guesser...Well, in that case, I must conceive an uncrackable code!" << endl;
    srand(time(0));
    vector<char> master(4);
    MasterPegs(master);

    cout << "Begin guessing whenever you are ready:" << endl;
    bool valid_input = false, victory = false;
    string user_guess_str;
    vector<char> user_guess_arr(4), correct_pegs(4);
    int turn = 0;
    char game_board[GAMEBOARD_ROWS][GAMEBOARD_COLS];
    do {
        do {
            cout << "-> ";
            cin >> user_guess_str;
            if (user_guess_str.size() != 4) {
                cout << "\nYou must enter exactly four colors! Please try again." << endl;
                cin.clear();
                cin.ignore(100,'\n');
            } else if (!CheckColor(user_guess_str)) {
                cout << "\nYou must enter four valid colors in a row!" << endl;
                cout << "Your choices are: (R)ed, (O)range, (Y)ellow, (G)reen, (B)lue, or (W)hite." << endl;
                cout << "Please try again." << endl;
                cin.clear();
                cin.ignore(100,'\n');
            } else {
                for (int i = 0; i < 4; i++) {
                    user_guess_arr[i] = user_guess_str.at(i);
                }
                valid_input = true;
                turn++;
            }
        } while (valid_input == false);
        
        vector<char> correct_pegs(4);
        ComparePegs(correct_pegs, master, user_guess_arr);

        BuildGameBoard(game_board, correct_pegs, user_guess_arr, turn);

        victory = GuesserWin(correct_pegs);

    } while (turn < 10 && !victory);

    if (victory) {
        cout << "Congratulations!! You have guessed my code!" << endl;
        if (turn == 1) {
            cout << "How did you guess it on the first try?? Surely you cheated!" << endl << "Regardless, ";
        } else {
            cout << "You took " << turn << " turns. It took you long enough!" << endl;
        }
        cout << "I will have to try harder next time..." << endl << endl;
    } else {
        cout << "Oh no! You have run out of guesses." << endl;
        cout << "The correct answer was \'";
        for (int i = 0; i < 4; i++) {
            cout << master[i];
        }
        cout << "\'." << endl << "Better luck next time!" << endl << endl;
    }
}

void MasterPegs(vector<char> &master_pegs) {
    int master_peg_num;
    char master_peg_col;
    vector<char> master(4);
    vector<char> mind(4);

    for(int i=0; i <= 4; i++) {
        master_peg_num = rand() % 6 + 1;
        switch (master_peg_num) {
            case 1:
                master_pegs[i] = 'R';
                break;
            case 2:
                master_pegs[i] = 'O';
                break;
            case 3:
                master_pegs[i] = 'Y';
                break;
            case 4:
                master_pegs[i] = 'G';
                break;
            case 5:
                master_pegs[i] = 'B';
                break;
            case 6:
                master_pegs[i] = 'W';
                break;
        }    
    }
}

bool CheckColor(string user_guess) {
    for (int i = 0; i < 4; i++) {
        if (user_guess.at(i) != 'R' && user_guess.at(i) != 'O' && user_guess.at(i) != 'Y' &&
            user_guess.at(i) != 'G' && user_guess.at(i) != 'B' && user_guess.at(i) != 'W') {
            return false;
        }
    }
    return true;
}

void ComparePegs(vector<char> &correct, vector<char> master, vector<char> guesser) {
    int correct_index = 0;
    for (int i = 0; i < 4; i++) {
        if (guesser[i] == master[i]) {
            correct[correct_index] = 'P';
            correct_index++;
            guesser[i] = 'X';
            master[i] = 'Z';
        }
    }
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            if (guesser[i] == master[j]) {
                correct[correct_index] = 'C';
                correct_index++;
                guesser[i] = 'X';
                master[j] = 'Z';
                break;
            } else {
                continue;
            }
        }
    }
    for (int i = 0; i < 4; i++) {
        if (correct[i] != 'P' && correct[i] != 'C') {
            correct[i] = ' ';
        }
    }
}

bool GuesserWin(vector<char> correct) {
    int P_count = 0;
    for (int i = 0; i < 4; i++) {
        if (correct[i] == 'P') {
            P_count++;
        }
    }
    if (P_count == 4) {
        return true;
    } else {
        return false;
    }
}

void Master() {

    cout << "\nI see you wish to be the Master...Very well then. I shall temporary relinquish my title." << endl;
    cout << "Fear not, though! I shall regain my Master title by guessing your code!" << endl;
    srand(time(0));
    vector<char> guesser(4), master(4), master_judge_arr(4), correct_pegs(4);
    string master_judge_str, master_code_str;
    bool valid_input = false, victory = false, valid_code = false;
    int turn = 0;
    char gameboard[GAMEBOARD_ROWS][GAMEBOARD_COLS];

    do {
        cout << "Enter your code: ";
        cin >> master_code_str;
        if (master_code_str.length() != 4) {
            cout << "\nYou must enter exactly four colors! Please try again." << endl;
            cin.clear();
            cin.ignore(100,'\n');
        } else if (!CheckColor(master_code_str)) {
            cout << "\nYou must enter four valid colors in a row!" << endl;
            cout << "Your choices are: (R)ed, (O)range, (Y)ellow, (G)reen, (B)lue, or (W)hite." << endl;
            cout << "Please try again." << endl;
            cin.clear();
            cin.ignore(100,'\n');
        } else {
            for (int m = 0; m < 4; m++) {
                master[m] = master_code_str.at(m);
            }
            valid_code = CheckColor(master_code_str);
        }
    } while (!valid_code);
    

    for (int i = 0; i < 10; i++) {
        MasterPegs(guesser);
        do {
            cout << "\nYour code: ";
            for (int code = 0; code < 4; code++) {
                cout << master[code];
            }
            cout << endl;
            BuildMasterBoard(gameboard,guesser,master_judge_arr,turn);
            cin >> master_judge_str;
            if (master_judge_str.length() > 4) {
                cout << "Your judgment should contain no more than four characters. Please try again." << endl;
                cin.clear();
                cin.ignore(100,'\n');
            } else {
                for (int j = 0; j < master_judge_str.length(); j++) {
                    master_judge_arr[j] = master_judge_str.at(j);
                }
                if (master_judge_str.length() < 4) {
                    for (int k = master_judge_str.length(); k < 4; k++) {
                        master_judge_arr[k] = ' ';
                    }
                }
                if (!CheckJudge(master_judge_arr)) {
                    cin.clear();
                    cin.ignore(100,'\n');
                } else {
                    ReorderJudge(master_judge_arr);
                    ComparePegs(correct_pegs,master,guesser);
                    valid_input = VerifyJudge(master_judge_arr,correct_pegs);
                    if (!valid_input) {
                        cout << "Are you sure about that? Try again..." << endl;
                    }
                }
            }
        } while (valid_input == false);
        turn++;
    }
}

void BuildGameBoard(char game_board[GAMEBOARD_ROWS][GAMEBOARD_COLS], vector<char> compare_pegs, vector<char> user_guess, int turn) {

    for (int i = 0; i < 4; i++) {
        game_board[turn-1][i] = compare_pegs[i];
        game_board[turn-1][i+4] = user_guess[i];   
    }
    cout << "Turn #" << turn << endl;
    for (int x = 0; x < turn; x++) {
        for (int y = 0; y < 4; y++) {
            cout << game_board[x][y];
        }
        cout << " | ";
        for (int z = 4; z < 8; z++) {
            cout << game_board[x][z];
        }
        cout << endl;
    }
    cout << endl;
}

bool CheckJudge(vector<char> judgment) {

    for (int i = 0; i < judgment.size(); i++) {
        if (judgment[i] != 'P' && judgment[i] != 'C' && judgment[i] != ' ') {
            return false;
        } else {
            continue;
        }
    }
    return true;
}

void ReorderJudge(vector<char> &judgment) {
    int P = 0, C = 0;
    for (int i = 0; i < judgment.size(); i++) {
        if (judgment[i] == 'P') {
            P++;
        } else if (judgment[i] == 'C') {
            C++;
        }
    }
    for (int p = 0; p < P; p++) {
        judgment[p] = 'P';
    }
    for (int c = 0; c < C; c++) {
        judgment[P+c] = 'C';
    }
    if ((P+C) < 4) {
        for (int s = P+C; s < 4; s++) {
            judgment[s] = ' ';
        }
    }
}

bool VerifyJudge(vector<char> user_judge, vector<char> actual_judge) {
    for (int i = 0; i < user_judge.size(); i++) {
        if (user_judge[i] == actual_judge[i]) {
            continue;
        } else {
            return false;
        }
    }
    return true;
}

void BuildMasterBoard(char game_board[GAMEBOARD_ROWS][GAMEBOARD_COLS], vector<char> master_sequence, vector<char> user_judge, int turn) {
    
    if (turn < 10) {
        cout << "Turn #" << turn + 1 << endl;
    }
    if (turn > 0 && turn < 10) {
        for (int i = 0; i < 4; i++) {
            game_board[turn-1][i+4] = user_judge[i];
            game_board[turn][i] = master_sequence[i];
        }
    } else if (turn == 0) {
        for (int j = 0; j < 4; j++) {
            game_board[turn][j] = master_sequence[j];
            cout << game_board[turn][j];
        }
        cout << " | ";
    } else {
        for (int k = 0; k < 4; k++) {
            game_board[turn-1][k+4] = user_judge[k];
        }
    }

    if (turn > 0 && turn < 10) {
        for (int x = 0; x < turn; x++) {
            for (int y = 0; y < 4; y++) {
                cout << game_board[x][y];
            }
            cout << " | ";
            for (int z = 4; z < 8; z++) {
                cout << game_board[x][z];
            }
            cout << endl;
        }
        for (int a = 0; a < 4; a++) {
            cout << game_board[turn][a];
        }
        cout << " | ";
    } else if (turn == 10) {
        for (int row = 0; row < GAMEBOARD_ROWS; row++) {
            for (int col = 0; col < GAMEBOARD_COLS; col++) {
                cout << game_board[row][col];
            }
            cout << endl;
        }
    }
}