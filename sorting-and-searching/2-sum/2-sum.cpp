#include <iostream>
#include <unordered_map>
#include <vector>
#include <algorithm>

using namespace std;

#define REP(i, a, b) for(int i = a; i < b; i++)
#define pb push_back

vector<pair<long, int>> nums;

int main(){
    long numVals, targetSum;
    cin >> numVals >> targetSum;

    long currNum;
    REP(i, 0, numVals){
        cin >> currNum;
        nums.pb({currNum, i});
    }
    sort(nums.begin(), nums.end());
    int l = 0, r = nums.size() - 1;
    while(l < r){
        long curr = nums[l].first + nums[r].first;
        if(curr > targetSum){
            r--;
        }
        else if(curr < targetSum){
            l++;
        }
        else{
            int trueL = nums[l].second + 1, trueR = nums[r].second + 1;
            cout << min(trueL, trueR) << " " << max(trueL, trueR) << endl;
            return 0;
        }
    }
    cout << "IMPOSSIBLE" << endl;
}
