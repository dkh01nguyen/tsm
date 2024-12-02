//
//  bellman.hpp
//  BTL CTRR
//
//  Created by Nguyễn Lâm on 09/06/2024.
//
#include <stack>
#include <string>

using namespace std;
void BF(int G[20][20], int n, char begin, int Val[], int Pre[]);
string BF_Path(int G[20][20], int n, char begin, char end);
