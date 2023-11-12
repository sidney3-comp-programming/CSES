/*
The Tower of Hanoi game consists of three stacks (left, middle and right) and n
round disks of different sizes. Initially, the left stack has all the disks, in increasing order of size from top to bottom.

The goal is to move all the disks to the right stack using the middle stack. On each move you can move the uppermost disk from a stack to another stack. In addition, it is not allowed to place a larger disk on a smaller disk.

Your task is to find a solution that minimizes the number of moves.

Approach: this is the classic recursion problem. Let dp(N, source, intermediate, target) be the sequence of moves that moves N stacked disks
from source to target. Then we are to return dp(N, 0, 1, 2). Note that intermediate is implied from source, target

What is the recursive relation, however?

Case of N = 1: just move it (i.e. source target)
Case of N = 2: use the middle disk as an intermediate for the smaller disk, move the smaller disk to tower 2, move the larger disk
to tower 3, and then move the smaller disk on top of the larger disk. In this problem, we represent this as:
source -> intermediate
source -> target
intermediate -> target
Case of N: perform the desired moves for DP(2) with source = source, target = intermediate. Then move largest disk from
source to target, then perform DP(2) moves with source = intermediate, target = target.

*/

#include <iostream>
#include <stdlib.h>
#include <vector>
#include <unordered_map>

#define pb push_back

using namespace std;

enum position {source, intermediate, target};

vector<pair<position, position>> memo[16];
unordered_map<position, position> initialIntermediateTranslationTable = { //for translating intermediate steps
    {source, source},
    {intermediate, target},
    {target, intermediate}
};
unordered_map<position, position> secondIntermediateTranslationTable = {
    {source, intermediate},
    {intermediate, source},
    {target, target}
};
unordered_map<position, int> responseTable = {
    {source, 1},
    {intermediate, 2},
    {target, 3}
};

vector<pair<position, position>> movesBetween(int sizeN){
    if(memo[sizeN].size() > 0){
        return memo[sizeN];
    }
    if(sizeN == 1){
        return {
            {source, target}
        };
    }
    vector<pair<position, position>> ans;

    for(const pair<position, position> &pos : movesBetween(sizeN - 1)){
        //gives the positions in terms of start, destination
        //but we want to convert destination to intermediate
        ans.pb({initialIntermediateTranslationTable[pos.first], initialIntermediateTranslationTable[pos.second]});
    }
    ans.pb({source, target});
    for(const pair<position, position> &pos : movesBetween(sizeN - 1)){
        ans.pb({secondIntermediateTranslationTable[pos.first], secondIntermediateTranslationTable[pos.second]});
    }
    return ans;
}

int main(){
    int n;
    cin >> n;
    vector<pair<position,position>> ans = movesBetween(n);
    cout << ans.size() << endl;
    for(const pair<position,position> &pos : movesBetween(n)){
        cout << responseTable[pos.first] << " " << responseTable[pos.second] << endl;
    }
}