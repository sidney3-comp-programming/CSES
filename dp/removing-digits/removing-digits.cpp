
#include <iostream>
#include <vector>
#include <cmath>
using namespace std;
/*
Let dp(i) be the minimum number of steps to reduce i to zero
*/

int INF = 10000001;
int  memo [1000001];
bool ready[1000001];

vector<int> digits(int target){
    vector<int> res;
    long curr = 10;

    while(curr <= target*10){
        res.push_back(
            floor((target % curr) / (curr / 10))
        );
        curr *= 10;
    }

    return res;
}

int backtrack(int target){
    if(target < 0){
        return INF;
    }
    if(ready[target]){
        return memo[target];
    }
    int res = target;
    for(int d : digits(target)){
        if(d != 0) res = min(res, 1 + backtrack(target - d));
    }
    ready[target] = true;
    memo[target] = res;
    return res;
}

int main(){
    int n;
    cin >> n;
    cout << backtrack(n) << endl;
}