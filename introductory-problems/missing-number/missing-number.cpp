/*
You are given all numbers between 1,2,...,n except for one, your tasl is to find the missing number
*/
#include <vector>
#include <iostream>
#include <stdio.h>

using namespace std;

int main() {
    int numVals;
    cin >> numVals;
    vector<int> nums;
    int currNum;
    for(int i = 0; i < numVals - 1; i++){
        cin >> currNum;
        nums.push_back(currNum);
    }

    nums.push_back(numVals + 1);
    for(int i = 0; i < numVals - 1; i++){
        nums[abs(nums[i])-1] *= -1;
    }
    for(int i = 0; i < numVals; i++){
        if(nums[i] > 0) {
            cout << i + 1;
        }
    }
}