#include <bits/stdc++.h>
/*
Given an array of n integers, your task is to process q queries of the following types: increase each value in range [a,b] by u

what is the value at position k?
*/
using namespace std;
#define REP(i,a,b) for(int i = a; i < b; i++)

unordered_set<int> starts;
unordered_set<int> ends;
int nums[200001];

int main(){
    int n,q;
    cin >> n >> q;
    REP(i, 0, n){
        cin >> nums[i];
    }
    int queryType, a,b,u,k;
    REP(j, 0, q){
        cin >> queries[j];
    }

}