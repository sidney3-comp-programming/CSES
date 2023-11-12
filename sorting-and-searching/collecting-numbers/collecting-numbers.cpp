/*
You are given an array that contains each number between 1…n exactly once. Your task is to collect the numbers from 1 to n in increasing order.

On each round, you go through the array from left to right and collect as many numbers as possible.
What will be the total number of rounds?

OH, this is just simulation - the order is fixed. But each simulation is O(n), so for example,

5 4 3 2 1 

would take a full 5 passes. You want perhaps some way to jump between indices? I want to make a hashmap from values
to indices
*/

#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

typedef vector<int> vi;

#define REP(i,a,b) for(int i = a; i < b; i++)
#define pb push_back

vi nums;
unordered_map<int, int> indices;

int main(){
    int numVals;
    cin >> numVals;
    int inpVal;
    REP(i, 0, numVals){
        cin >> inpVal;
        nums.pb(inpVal);
        indices[inpVal] = i;
    }
    int currVal = 1, res = 1;
    // 4 2 1 5 3
    while(currVal < numVals){
        if(indices[currVal] > indices[currVal + 1]){
            res++;
        }
        currVal++;
    }
    cout << res << endl;
}