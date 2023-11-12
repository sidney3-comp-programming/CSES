#include <bits/stdc++.h>
using namespace std;
#define ll long long

int dp[501][100000];
int ready[501][100000];
int MOD = (int) (1e9 + 7);

int backtrack(int i, int j){
    if(j == 0){
        return 1;
    }
    if(i < 0 || j < 0){
        return 0;
    }
    if(ready[i][j])
        return dp[i][j];

    dp[i][j] = backtrack(i - 1, j);
    if(j >= i){
        dp[i][j] += backtrack(i - 1, j - i);
    }
    dp[i][j] %= MOD;
    ready[i][j] = true;
    return dp[i][j];
}

int main(){
    int n;
    cin >> n;
    if(n%4 == 0 || (n+1)%4 == 0){
        int target = ((n+1)*n) / 4;
        int res = backtrack(n - 1, target);
        cout << res << endl;
    }
    else{
        cout << 0 << endl;
    }
}



