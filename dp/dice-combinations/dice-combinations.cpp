/*
Your task is to count the number of ways to construct sum n
 by throwing a dice one or more times. Each throw produces an outcome between 1
 and 6.

Our result equals

the number of ways to make target with i throws + number of ways
to make target with i - 1 throws.

Too many states!

Why not just keep an array of the current number of ways we've been able to make each
value.

Then, with each new throw, we get a bunch of new potential values! Too many operations...
Again O(n^2), as we have to query...

Let dp(i,j) denote the number of ways to make some value i with allotted throws. Again
n^2 states, but many of them aren't possible. Far too many states.

Fix the number of throws. How many ways are there to make the target value with
exactly k throws? We need information about only the prior state...

Sure, so we can keep an array prior combinations that represents our prior state. Bound to 
be less than n states
*/


#include <iostream>

using namespace std;

#define REP(i,a,b) for(int i = a; i < b; i++)

long INF = 1000000007;
int dp[2000000];


int main(){
    int n;
    cin >> n;
    dp[0] = 1;
    REP(i, 1, n + 1){
        REP(side, 1, 7){
            if(i - side >= 0){
                dp[i] = (dp[i] + dp[i - side]) % INF;
            }
        }
    }
    cout << dp[n] << endl;
}


