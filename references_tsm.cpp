#include "tsm.h"
using namespace std;

void constructor(int G[20][20], int n, char start, int &Gmin,int X[20], bool visited[20] ){
    
    for (int i = 0; i < n; ++i){
        for (int j = 0; j < n; ++j){
            if (G[i][j] != 0 ){
                Gmin = min(G[i][j], Gmin);
            } 
        }
    }

    for (int i = 0; i < n; ++i){
        visited[i] = false;
    }
    
    int a = start - 65;
    X[0] = a;
    visited[a] = true;
}


void Try(int i, int G[20][20], int n, int Gmin,int X[20], bool visited[20], int BFPrev[20], int &d, int& ans){
    
    for (int j = 0; j < n; ++j){
        
        if (visited[j] == true) continue;
        else if (visited[j] == false) {
            X[i-1] = j;
            visited[j] = true;
            
            if (!(G[X[i-2]][X[i-1]] == 0)) {
                
                d = d + G[X[i-2]][X[i-1]];
                
                if (i == n){
                    int dis =  d + G[X[n-1]][X[0]];
                    int check = ans;
                    
                    if (G[X[n-1]][X[0]] != 0 && ans > dis){
                        ans = dis;
                    }
                    
                    if (check != ans){
                        for (int k = 0; k < n; ++k){
                            BFPrev[k] = X[k];
                        }
                    }
                
                } else if (d + (n - i + 1)* Gmin < ans) {
                    
                    Try(i+1,G,n,Gmin,X,visited,BFPrev,d,ans);
                } 

                d = d - G[X[i-2]][X[i-1]];
                
            }

            visited[j] = false;

        }
    }
    return;

}

string change(int BFPrev[20], char start,int n){
    
    int a = start - 65;
    BFPrev[n] = a;

    string kq = "1";
    
    kq[0] = (char)(BFPrev[0] + 65);
    for (int i = 1; i <= n; i++){
       kq.append("01");
       kq[kq.length() - 2] = ' ';
       kq[kq.length() - 1] = (char)(BFPrev[i] + 65);
    }
    
    return kq;
}
string Traveling(int G[20][20], int n, char start){
    
    
    int INF = 2147483647;
    int X[20];
    bool visited[20];
    int BFPrev[20];
    int d = 0, ans = INF, Gmin = INF;



    constructor(G,n,start,Gmin,X,visited);

    
    Try(2,G,n,Gmin,X,visited,BFPrev,d,ans);
    

    string kq = change(BFPrev,start,n);
    return kq;


}
int main(){
    int G[20][20];
    for (int i = 0; i < 5; i++){
        for (int j = 0; j < 5; j++){
            G[i][j] = 0;
        }
    }
    G[0][1] = G[1][0] = 8;
    G[0][3] = G[3][0] = 1;
    G[0][4] = G[4][0] = 3;
    G[1][2] = G[2][1] = 3;
    G[1][3] = G[3][1] = 3;
    G[3][4] = G[4][3] = 7;
    G[4][2] = G[2][4] = 4;
    cout << Traveling(G,5,'A');
}