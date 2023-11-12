#include <bits/stdc++.h>
using namespace std;


bool ready[501][501];
int memo[501][501];
int MAX_RES = 500*500;

int backtrack(int i,int j){
    if(i == j){
        return 0;
    }
    if(ready[i][j]){
        return memo[i][j];
    }
    if(ready[j][i]){
        return memo[j][i];
    }
    int res = MAX_RES;
    for(int xCut = 1; xCut < i; xCut++){
        res = min(res, 1 + backtrack(xCut, j) + backtrack(i - xCut, j));
    }
    for(int yCut = 1; yCut < j; yCut++){
        res = min(res, 1 + backtrack(i, yCut) + backtrack(i, j - yCut));
    }
    ready[i][j] = true;
    ready[j][i] = true;
    memo[i][j] = res;
    memo[j][i] = res;
    return res;
}

int main(){
    int a,b;
    cin >> a >> b;
    cout << backtrack(a,b) << endl;
}