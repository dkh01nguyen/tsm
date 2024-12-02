#include "bellman.h"

using namespace std;

void BF(int G[30][30], int n, char begin, int bf_value[], int bf_previous[]) {
    int value[30];
    int previous[30];
    int s = begin - 'A';
    int sum = 0;
    for (int i = 0; i < n; i++) {
        sum += bf_value[i];
    }
    if (sum == -n) {
        for (int i = 0; i < n; i++) {
            if (i != s) {
                bf_value[i] = G[s][i] == 0 ? -1 : G[s][i];
                bf_previous[i] = G[s][i] == 0 ? -1 : s;
            }
            else { 
                bf_value[i] = 0;
                bf_previous[i] = -1;
            }
        }
        return;
    }

    for (int i = 0; i < n; i++) {
        value[i] = bf_value[i];
        previous[i] = bf_previous[i];
    }

    for (int u = 0; u < n; u++) {
        if (u == s || bf_value[u] == 0) continue;
        for (int v = 0; v < n; v++) {
            if (G[v][u] > 0 && bf_value[v] != -1 &&
                 (bf_value[v] + G[v][u] < value[u] || value[u] == -1)) {
                value[u] = bf_value[v] + G[v][u];
                previous[u] = v;
            }
        }
    }

    for (int i = 0; i < n; i++) {
        bf_value[i] = value[i];
        bf_previous[i] = previous[i];
    }
}

string BF_Path(int G[30][30], int n, char begin, char end) {
    int bf_value[30], bf_previous[30];
    for (int i = 0; i < n; i++) {
        bf_value[i] = -1;
        bf_previous[i] = -1;
    }

    BF(G, n, begin, bf_value, bf_previous);

    while (true) {
        int ValCopy[30];
        for (int i = 0; i < n; i++) {
            ValCopy[i] = bf_value[i];
        }
        
        BF(G, n, begin, bf_value, bf_previous);

        bool done = true;
        for (int i = 0; i < n; i++) {
            if (bf_value[i] != ValCopy[i]) {
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
        while (bf_previous[crawl] != -1) {
            path.push(char('A' + bf_previous[crawl]));
            crawl = bf_previous[crawl];
        }

        string result = "";
        while (!path.empty()) {
            result += path.top();
            path.pop();
            if (!path.empty()) result += " ";
        }
        return result;
}
