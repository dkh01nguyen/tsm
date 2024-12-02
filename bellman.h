#ifndef BELLMAN_H
#define BELLMAN_H

#include <iostream>
#include <string>
#include <climits>
#include <stack>

#define MAX_CITY 30

void BF(int map[MAX_CITY][MAX_CITY], int n, char begin, int bf_value[MAX_CITY], int bf_previous[MAX_CITY]);

std::string BF_Path(int G[MAX_CITY][MAX_CITY], int n, char begin, char end);

#endif