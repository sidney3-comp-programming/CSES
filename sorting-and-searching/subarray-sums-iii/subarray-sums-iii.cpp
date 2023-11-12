#include <bits/stdc++.h>
using namespace std;

#define REP(i,a,b) for(int i = a; i < b; i++)

int abs_mod(int k, int n){
    return ((k % n) + n) % n;
}

int main(){
    int n;
    cin >> n;
    vector<int> arr(n);
    unordered_map<int,int> mp;
    mp[0]++;
    REP(i,0,n) cin >> arr[i];
    int curr = 0;
    long res = 0;
    REP(i,0,n){
        curr += arr[i];
        curr = abs_mod(curr, n);
        if(mp.count(curr)) res += (long) mp[curr];
        mp[curr]++;
    }
    cout << res<< endl;
}