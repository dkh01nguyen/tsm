//
//  bellman.cpp
//  BTL CTRR
//
//  Created by Nguyễn Lâm on 09/06/2024.
//


#include "bellman.h"
#include <stack>
#include <string>

using namespace std;

void BF(int G[30][30], int n, char begin, int Val[], int Pre[]) {
    int Val1[30];
    int Pre1[30];
    int s = begin - 'A';
    int sum = 0;
    for (int i = 0; i < n; i++) {
        sum += Val[i];
    }
    if (sum == -n) {
        for (int i = 0; i < n; i++) {
            if (i != s) {
                Val[i] = G[s][i] == 0 ? -1 : G[s][i];
                Pre[i] = G[s][i] == 0 ? -1 : s;
            }
            else { 
                Val[i] = 0;
                Pre[i] = -1;
            }
        }
        return;
    }

    for (int i = 0; i < n; i++) {
        Val1[i] = Val[i];
        Pre1[i] = Pre[i];
    }

    for (int u = 0; u < n; u++) {
        if (u == s || Val[u] == 0) continue;
        for (int v = 0; v < n; v++) {
            if (G[v][u] > 0 && Val[v] != -1 &&
                 (Val[v] + G[v][u] < Val1[u] || Val1[u] == -1)) {
                Val1[u] = Val[v] + G[v][u];
                Pre1[u] = v;
            }
        }
    }

    for (int i = 0; i < n; i++) {
        Val[i] = Val1[i];
        Pre[i] = Pre1[i];
    }
}
string BF_Path(int G[30][30], int n, char begin, char end) {
    int Val[30], Pre[30];
    for (int i = 0; i < n; i++) {
        Val[i] = -1;
        Pre[i] = -1;
    }

    BF(G, n, begin, Val, Pre);

    while (true) {
        int ValCopy[30];
        for (int i = 0; i < n; i++) {
            ValCopy[i] = Val[i];
        }
        
        BF(G, n, begin, Val, Pre);

        bool done = true;
        for (int i = 0; i < n; i++) {
            if (Val[i] != ValCopy[i]) {
                done = false;
                break;
            }
        }
        if (done) break;
    }

    int target = end - 'A';
        stack<char> path;
        int crawl = target;
        path.push(end);
        while (Pre[crawl] != -1) {
            path.push(char('A' + Pre[crawl]));
            crawl = Pre[crawl];
        }

        string result = "";
        while (!path.empty()) {
            result += path.top();
            path.pop();
            if (!path.empty()) result += " ";
        }
        return result;
}

