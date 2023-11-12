#include <iostream>
#include <vector>

using namespace std;


int MOD = (int)1e9 + 7;
int  dp   [1000001];

int main(){
    int n,x;
    cin >> n >> x;
    vector<int> coins(n);
    for(int i = 0; i < n; i++){
        cin >> coins[i];
    }
    dp[0] = 1;
    for(int i = 1; i <= x; i++){
        for(int coin : coins){
            if(i - coin >= 0){
                dp[i] = dp[i] + dp[i - coin];
                dp[i] %= MOD;
            }
        }
    }
    cout << dp[x] << endl;
}