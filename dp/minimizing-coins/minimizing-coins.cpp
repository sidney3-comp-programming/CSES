/*
Let dp(i) be the minimum number of coins to produce i

*/

#include <iostream>
#include <vector>

using namespace std;
#define REP(i,a,b) for(int i = a; i < b; i++)

int dp[2000000];
vector<int> coins;

int main(){
    int n,x;
    cin >> n >> x;
    fill(&dp[0],&dp[0] + sizeof(dp) / sizeof(int), x + 1);
    dp[0] = 0;

    int y;
    REP(i, 0 , n){
        cin >> y;
        coins.push_back(y);
    }

    REP(i, 1, x + 1){
        for(int c : coins){
            if(i - c >= 0){
                dp[i] = min(dp[i], 1 + dp[i - c]);
            }
        }
    }
    if(dp[x] == x + 1){
        cout << -1;
    }
    else{
        cout << dp[x];
    }
}