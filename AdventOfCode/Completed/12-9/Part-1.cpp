#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>

using namespace std;

class Node {
    public:
    bool visited = false;
    int x = 0;
    int y = 0;
    char character = '.';
};

int main() {
    ifstream fin;
    string line;
    Node my_array[398][398];
    for (int i = 0; i < 398; i++) {
        for (int j = 0; j < 398; j++) {
            my_array[i][j].y = i;
            my_array[i][j].x = j;
        }
    }
    Node H, T;
    H.x = 240;
    H.y = 180;
    T.x = 240;
    T.y = 180;

    char direction;
    int number;
    fin.open("tail.txt");
    if (!fin.is_open()) {
        cerr << "ERROR! Could not open tree.txt." << endl;
    } else {
        while (getline(fin, line)) {
            stringstream parseline(line);
            parseline >> direction;
            parseline >> number;
            bool two_apart;
            if (direction == 'U') {
                for (int i = 0; i < number; i++) {
                    H.y = H.y - 1;
                    two_apart = T.y - H.y == 2;
                    if (two_apart) {
                        T.y = T.y - 1;
                        if (H.x - T.x == 1) {
                            T.x = T.x + 1;
                        } else if (T.x - H.x == 1) {
                            T.x = T.x - 1;
                        }
                    }
                    my_array[T.y][T.x].visited = true;
                    my_array[T.y][T.x].character = '#';
                }
                // moveUp(my_array, H, T, number);
            } else if (direction == 'D') {
                // moveDown(my_array, H, T, number);
                for (int i = 0; i < number; i++) {
                    H.y++;
                    two_apart = H.y - T.y == 2;
                    if (two_apart) {
                        T.y++;
                        if (H.x - T.x == 1) {
                            T.x++;
                        } else if (T.x - H.x == 1) {
                            T.x--;
                        }
                    }
                    my_array[T.y][T.x].visited = true;
                    my_array[T.y][T.x].character = '#';
                }
            } else if (direction == 'L') {
                for (int i = 0; i < number; i++) {
                    H.x--;
                    two_apart = T.x - H.x == 2;
                    if (two_apart) {
                        T.x--;
                        if (H.y - T.y == 1) {
                            T.y++;
                        } else if (T.y - H.y == 1) {
                            T.y--;
                        }
                    }
                    my_array[T.y][T.x].visited = true;
                    my_array[T.y][T.x].character = '#';
                }
                // moveLeft(my_array, H, T, number);
            } else if (direction == 'R') {
                for (int i = 0; i < number; i++) {
                    H.x++;
                    two_apart = H.x - T.x == 2;
                    if (two_apart) {
                        T.x++;
                        if (H.y - T.y == 1) {
                            T.y++;
                        } else if (T.y - H.y == 1) {
                            T.y--;
                        }
                    }
                    my_array[T.y][T.x].visited = true;
                    my_array[T.y][T.x].character = '#';
                }
                // moveRight(my_array, H, T, number);
            }
        }
    }
    fin.close();

    int visited = 0;
    for (int i = 0; i < 398; i++) {
        for (int j = 0; j < 398; j++) {
            if (my_array[i][j].visited) {
                visited++;
                // cout << my_array[i][j].x << "," << my_array[i][j].y << endl;
            }
            cout << my_array[i][j].character;
        } cout << endl;
    }

    cout << endl << "Visited: " << visited << endl;

    return 0;
}
