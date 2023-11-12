#include <bits/stdc++.h>
using namespace std;

#define REP(i,a,b) for(int i = a; i < b; i++)

typedef vector<int> vi;
typedef long long ll;

ll arr[5001];
ll pfx[5001];
bool ready[5001][5001];
ll memo[5001][5001];

ll backtrack(int i, int j){
    if(i == j){
        return arr[i];
    }
    if(ready[i][j]){
        return memo[i][j];
    }
    ll S = pfx[j];
    if(i > 0){
        S -= pfx[i-1];
    }
    memo[i][j] = S - min(backtrack(i+1, j), backtrack(i, j - 1));
    ready[i][j] = true;
    return memo[i][j];
}

int main(){
    int n;
    cin >> n;
    REP(i, 0, n){
        cin >> arr[i];
    }
    pfx[0] = arr[0];
    REP(j, 1, n){
        pfx[j] = pfx[j-1] + arr[j];
    }
    cout << backtrack(0, n - 1) << endl;
}