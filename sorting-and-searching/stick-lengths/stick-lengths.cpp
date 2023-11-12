#include <algorithm>
#include <iostream>
#include <cmath>
#include <vector>

using namespace std;

#define pb push_back
#define REP(i,a,b) for(int i = a; i < b; i++)


vector<long> nums;

int main(){
    int numVals;
    long curr;
    cin >> numVals;
    REP(i, 0, numVals){
        cin >> curr;
        nums.pb(curr);
    }
    sort(nums.begin(), nums.end());
    int median = nums[floor(nums.size() / 2)];

    long res = 0;
    REP(i, 0, numVals){
        res += abs(median - nums[i]);
    }
    cout << res << endl;
}