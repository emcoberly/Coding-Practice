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

void moveTail(Node &H, Node &T);

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
    Node H, One, Two, Three, Four, Five, Six, Seven, Eight, T;
    vector<Node> knots = {H, One, Two, Three, Four, Five, Six, Seven, Eight, T};
    for (int i = 0; i < knots.size(); i++) {
        knots.at(i).x = 240;
        knots.at(i).y = 180;
    }

    char direction;
    int number;

    fin.open("tail.txt");
    if (!fin.is_open()) {
        cerr << "ERROR! Could not open tail.txt." << endl;
    } else {
        while (getline(fin, line)) {
            stringstream parseline(line);
            parseline >> direction;
            parseline >> number;
            for (int j = 0; j < number; j++) {
                if (direction == 'U') {
                    knots.at(0).y--;
                } else if (direction == 'D') {
                    knots.at(0).y++;
                } else if (direction == 'L') {
                    knots.at(0).x--;
                } else if (direction == 'R') {
                    knots.at(0).x++;
                }
                for (int i = 0; i < knots.size() - 1; i++) {
                    moveTail(knots.at(i), knots.at(i+1));
                }
                my_array[knots.back().y][knots.back().x].visited = true;
                my_array[knots.back().y][knots.back().x].character = '#';
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
            // if (j == knots.at(0).x && i == knots.at(0).y) {
            //     cout << 'H';
            // } else if (j == knots.at(1).x && i == knots.at(1).y) {
            //     cout << '1';
            // } else if (j == knots.at(2).x && i == knots.at(2).y) {
            //     cout << '2';
            // } else if (j == knots.at(3).x && i == knots.at(3).y) {
            //     cout << '3';
            // } else if (j == knots.at(4).x && i == knots.at(4).y) {
            //     cout << '4';
            // } else if (j == knots.at(5).x && i == knots.at(5).y) {
            //     cout << '5';
            // } else if (j == knots.at(6).x && i == knots.at(6).y) {
            //     cout << '6';
            // } else if (j == knots.at(7).x && i == knots.at(7).y) {
            //     cout << '7';
            // } else if (j == knots.at(8).x && i == knots.at(8).y) {
            //     cout << '8';
            // } else if (j == knots.at(9).x && i == knots.at(9).y) {
            //     cout << 'T';
            // } else {
            //     cout << my_array[i][j].character;
            // }
        } // cout << endl;
    }

    cout << endl << "Visited: " << visited << endl;

    return 0;
}

void moveTail(Node &H, Node &T) {
    bool u1 = T.y - H.y > 1;
    bool d1 = H.y - T.y > 1;
    bool l1 = T.x - H.x > 1;
    bool r1 = H.x - T.x > 1;
    bool u2 = T.y > H.y;
    bool d2 = H.y > T.y;
    bool l2 = T.x > H.x;
    bool r2 = H.x > T.x;
    if (u1) {
        T.y--;
        if (l2) {
            T.x--;
        } else if (r2) {
            T.x++;
        }
    } else if (d1) {
        T.y++;
        if (l2) {
            T.x--;
        } else if (r2) {
            T.x++;
        }
    } else if (l1) {
        T.x--;
        if (u2) {
            T.y--;
        } else if (d2) {
            T.y++;
        }
    } else if (r1) {
        T.x++;
        if (u2) {
            T.y--;
        } else if (d2) {
            T.y++;
        }
    }
}
