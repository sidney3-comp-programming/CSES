#include <bits/stdc++.h>
using namespace std;

#define REP(i,a,b) for(int i = a; i < b; i++)
typedef long long ll;

int main(){
    ll n, sum;
    cin >> n >> sum;
    vector<ll> arr(n);
    unordered_map<ll,ll> mp;
    REP(i,0,n) cin >> arr[i];
    ll curr = 0, res = 0;
    REP(i,0,n){
        curr += arr[i];
        if(curr == sum) res++;
        if(mp.count(curr - sum)) res += mp[curr-sum];
        mp[curr]++;
    }
    cout << res<< endl;
}