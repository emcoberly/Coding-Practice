#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <stack>

using namespace std;

class Tree {
    public:
    int height;
    bool visible;
};

int main() {
    ifstream fin;
    string line;
    vector<string> treerow(0);
    char tree = 'x';
    vector<Tree> trees(0);
    vector<vector<Tree>> forest(0);

    fin.open("tree.txt");
    if (!fin.is_open()) {
        cerr << "ERROR! Could not open tree.txt." << endl;
    } else {
        while (getline(fin, line)) {
            treerow.push_back(line);
            // cout << line << endl;
        }
    }
    fin.close();

    for (int i = 0; i < treerow.size(); i++) {
        Tree temptree;
        for (int j = 0; j < treerow.at(i).size(); j++) {
            temptree.height = treerow.at(i).at(j) - 48;
            trees.push_back(temptree);
        }
        forest.push_back(trees);
        trees = {};
    }

    Tree currTree;
    for (int i = 0; i < forest.size(); i++) {
        for (int j = 0; j < forest.at(i).size(); j++) {
            currTree = forest.at(i).at(j);
            cout << currTree.height;
        } cout << endl;
    }

    int maxtree;
    for (int i = 0; i < forest.size(); i++) {
        maxtree = 0;
        for (int j = 0; j < forest.at(i).size(); j++) {
            currTree = forest.at(i).at(j);
            if (currTree.height > maxtree) {
                currTree.visible = true;
                maxtree = currTree.height;
            } else {
                currTree.visible = false;
            }
            if (i == 0 || i == forest.size() - 1 || j == 0 || j == forest.at(i).size() - 1) {
                currTree.visible = true;
            }
            forest.at(i).at(j) = currTree;
        }
        maxtree = 0;
        for (int k = forest.at(i).size() - 1; k >= 0; k--) {
            currTree = forest.at(i).at(k);
            if (currTree.height > maxtree) {
                maxtree = currTree.height;
                currTree.visible = true;
            } else {
                if (currTree.visible != true) {
                    currTree.visible = false;
                }
            }
            forest.at(i).at(k) = currTree;
        }
    }
    for (int i = 0; i < line.size(); i++) {
        maxtree = 0;
        for (int j = 0; j < forest.size(); j++) {
            currTree = forest.at(j).at(i);
            if (currTree.height > maxtree) {
                maxtree = currTree.height;
                currTree.visible = true;
            } else {
                if (currTree.visible != true) {
                    currTree.visible = false;
                }
            }
            forest.at(j).at(i) = currTree;
        }
        maxtree = 0;
        for (int k = forest.size() - 1; k >= 0; k--) {
            currTree = forest.at(k).at(i);
            if (currTree.height > maxtree) {
                maxtree = currTree.height;
                currTree.visible = true;
            } else {
                if (currTree.visible != true) {
                    currTree.visible = false;
                }
            }
            forest.at(k).at(i) = currTree;
        }
    }
    
    int visible = 0;
    for (int i = 0; i < forest.size(); i++) {
        for (int j = 0; j < forest.at(i).size(); j++) {
            currTree = forest.at(i).at(j);
            cout << currTree.visible;
            visible += currTree.visible;
        } cout << endl;
    }

    cout << "Visible trees: " << visible << endl;

    return 0;
}
