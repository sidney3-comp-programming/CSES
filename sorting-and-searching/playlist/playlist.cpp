#include <iostream>
#include <set>
#include <vector>
#include <unordered_set>

using namespace std;

#define REP(i,a,b) for(int i = a; i < b; i++)
#define pb push_back

set<int> visited;

int main(){
    int numVals, curr;
    cin >> numVals;
    int currNum, l = 0, res = 0;
    vector<int> nums;
    REP(_, 0, numVals){
        cin >> curr;
        nums.pb(curr);
    }
    

    REP(r, 0, numVals){
        while(visited.count(nums[r]) > 0){
            visited.erase(nums[l]);
            l++;
        }
        res = max(res, r - l + 1);
        visited.insert(nums[r]);
    }
    cout << res << endl;
}