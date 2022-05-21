#pragma once
#include <iostream>
#include <vector>
#include <random>
#include <ctime>
#include <map>
using namespace std;

vector<int> rollDice(vector<int> ignore = {0,0,0,0,0});
void displayDice(vector<int> my_dice);
void saveDice(vector<int> &my_dice);
void saveScore(vector<int> my_dice, map<string,int> &player_score, int turns_taken);
void scoreboard(map<string,int> scores={});
int sumDice(vector<int> my_dice);
bool gameOver(map<string,int> scores_list);
