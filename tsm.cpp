#include "tsm.h"

using namespace std;

void prep(bool visit[30], int dasequence[30], int graph[30][30], int &gmin, int n, char begin) {
    for (int i = 0; i < n; i++){
        visit[i] = false;
    }
    for (int i = 0; i < n; i++){
        dasequence[i] = 0;
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++){
            if (graph[i][j] != 0) gmin = min(gmin, graph[i][j]);
        }
    }
    visit[begin - 'A'] = true;
    dasequence[0] = begin - 'A';
}

void step(int i, int graph[30][30], int n, bool visit[30], int dasequence[30], int &d, int daroute[30], int &ans, int gmin){

    for (int j = 0; j < n; j++) {

        if (visit[j] == false) {

            dasequence[i - 1] = j;
            visit[j] = true;

            if (!(graph[dasequence[i - 2]][dasequence[i - 1]] == 0)) {

                d += graph[dasequence[i - 2]][dasequence[i - 1]];

                if (i == n){
                    int final_cost = d + graph[dasequence[n - 1]][0];
                    int final_route = ans;
                    if (graph[dasequence[n - 1]][0] != 0) {
                        ans = min(ans,final_cost);
                    }

                    if (final_route != ans) {
                        for (int k = 0; k < n; k++) {
                            daroute[k] = dasequence[k];
                        }
                        daroute[n] = daroute[0];
                    }
                }
                else if (d + (n - i + 1) * gmin < ans){
                    step(i + 1, graph, n, visit, dasequence, d, daroute, ans, gmin);
                }

                d -= graph[dasequence[i - 2]][dasequence[i - 1]];
            }
            visit[j] = false;

        }
    }
    return;
}

string convert(int daroute[30], int n){
    string result = "";
    int i = 0;
    while(i <= n){
        result = result + (char)(daroute[i] + 65) + ' ';
        i++;
    }
    result.pop_back();
    return result;
}

string traveling(int graph[30][30], int vertices, char fv) {

    bool visited[30];
    int sequence[30];
    int route[30];
    int d = 0, ans = INT_MAX;
    int gmin = INT_MAX; 

    prep(visited, sequence, graph, gmin, vertices, fv);

    step(2, graph, vertices, visited, sequence, d, route, ans, gmin);

    string finale = convert(route,vertices);

    return finale;
}