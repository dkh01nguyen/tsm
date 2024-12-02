#ifndef TSM_H
#define TSM_H

#include <iostream>
#include <iomanip>
#include <cmath>
#include <cstring>
#include <climits>
#include <string>
#include <algorithm>

void prep(bool visit[30], int dasequence[30], int graph[30][30], int &gmin, int n, char begin);
void step(int i, int graph[30][30], int n, bool visit[30], int dasequence[30], int &d, int daroute[30], int &ans, int gmin);
std::string convert(int daroute[30], int n);
std::string traveling(int graph[30][30], int vertices, char fv);

#endif