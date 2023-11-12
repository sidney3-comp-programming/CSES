/*
There are n apples with known weights. Your task is to divide the apples into two groups so that the difference
between the weights of the groups is minimal.

Input
The first input line has an integer n : the number of apples.
The next line has n integers p1,p2,…,pn : the weight of each apple.

Output
Print one integer: the minimum difference between the weights of the groups.
Constraints
1≤n≤20
1≤p_i <= 1e9


N small so backtracking... 2^20 possible splits. How do we properly represent the states? Want to return the number
of apples that we've assigned to each set, the current value of set1, and the current value of set2
*/

#include <iostream>
#include <cmath>
#include <vector>

#define REP(i,a,b) for(int i = a; i < b; i++)

using namespace std;

vector<long> appleWeights;

long backtrack(int i, long left, long right){
    if(i == appleWeights.size()){
        return abs(left - right);
    }
    return min(backtrack(i+1, left + appleWeights[i], right), backtrack(i+1, left, right + appleWeights[i]));
}


int main(){
    int n;
    cin >> n;

    long currApple;

    REP(i, 0, n){
        cin >> currApple;
        appleWeights.push_back(currApple);
    }

    cout << backtrack(0, 0, 0) << endl;
}