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
    int x, y;
    int left = 0, right = 0, up = 0, down = 0;
};

int getDistance(Tree tree, vector<vector<Tree>> tree_vec);

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
    
    int maxDist = 0;
    int visible = 0;
    for (int i = 0; i < forest.size(); i++) {
        for (int j = 0; j < forest.at(i).size(); j++) {
            currTree = forest.at(i).at(j);
            // cout << currTree.visible;
            visible += currTree.visible;
            currTree.x = i;
            currTree.y = j;
            forest.at(i).at(j) = currTree;
            cout << getDistance(currTree, forest) << " ";
            if (getDistance(currTree, forest) > maxDist) {
                maxDist = getDistance(currTree, forest);
            }
        } cout << endl;
    }

    cout << "Visible trees: " << visible << endl;
    cout << "Max visibility: " << maxDist << endl;

    return 0;
}

int getDistance(Tree tree, vector<vector<Tree>> tree_vec) {
    for (int i = tree.x - 1; i >= 0; i--) {
        if (tree.height > tree_vec.at(i).at(tree.y).height) {
            tree.left++;
        } else {
            tree.left++;
            break;
        }
    }
    for (int j = tree.x + 1; j < tree_vec.at(0).size(); j++) {
        if (tree.height > tree_vec.at(j).at(tree.y).height) {
            tree.right++;
        } else {
            tree.right++;
            break;
        }
    }
    for (int k = tree.y - 1; k >= 0; k--) {
        if (tree.height > tree_vec.at(tree.x).at(k).height) {
            tree.up++;
        } else {
            tree.up++;
            break;
        }
    }
    for (int l = tree.y + 1; l < tree_vec.size(); l++) {
        if (tree.height > tree_vec.at(tree.x).at(l).height) {
            tree.down++;
        } else {
            tree.down++;
            break;
        }
    }
    return tree.left * tree.right * tree.up * tree.down;
}
