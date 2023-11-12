#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

typedef vector<int> vi;

#define REP(i,a,b) for(int i = a; i < b; i++)
#define pb push_back
#define INF 1e13


int main(){
    /*
    The trick: can't reuse coins. Sort coins. We let res such that
    we can represent 0,...,res - 1 (res is initialized to 1). When we hit a new value, if
    that value exceeds res, then we know that we will be unable to produce res, and thus we return it.

    Else, we update res to res + new_value, as we can now represent all th
    */
   int numCoins;
   cin >> numCoins;
   vector<long> coins;
   long currCoin;
   REP(i, 0, numCoins){
    cin >> currCoin;
    coins.pb(currCoin);
   }
   sort(coins.begin(), coins.end());
   long res = 1;
   REP(i, 0, coins.size()){
    if(coins[i] > res){
        cout << res << endl;
        return 0;
    }
    else{
        res += coins[i];
    }
   }
   cout << res << endl;
}