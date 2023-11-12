#include <iostream>
#include <stdio.h>
#include <vector>
#include <string.h>

using namespace std;

/*
Greedy approach: front to back, perform the minimum number of moves necessary
*/
int main(){
    int n;
    cin >> n;
    int in;
    vector<int> nums;
    for(int i = 0; i < n; i++){
        cin >> in;
        nums.push_back(in);
    }
    long res = 0;
    int currNum = nums[0];

    for(int i = 1; i < n; i++){
        if(nums[i] < currNum) {
            res += currNum - nums[i];
        }
        else{
            currNum = nums[i];
        }
    }
    cout << res;
}