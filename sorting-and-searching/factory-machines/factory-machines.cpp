#include <bits/stdc++.h>
using namespace std;

#define ll long long

ll MAX_TIME = (ll) 1e18;
int n, t;
ll machine[200001];

bool canSolve(ll time){
    ll machinesMade = 0;
    for(int j = 0; j < n; j++){
        if(machinesMade >= t){
            return true;
        }
        machinesMade += (time / machine[j]);
    }
    return machinesMade >= t;
}
int main(){
    cin >> n >> t;
    for(int i = 0; i < n; i++){
        cin >> machine[i];
    }
    ll l = 0;
    ll r = MAX_TIME;
    ll res = -1;
    while(l <= r){
        ll m = (l+r) / 2;
        if(canSolve(m)){
            r = m - 1;
            res = m;
        }
        else{
            l = m + 1;
        }
    }
    cout << res << endl;
}