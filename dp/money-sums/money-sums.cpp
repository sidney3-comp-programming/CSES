#include <bits/stdc++.h>
using namespace std;

#define REP(i,a,b) for(int i = a; i < b; i++)

typedef vector<int> vi;

int main(){
    int n;
    cin >> n;
    vi coins(n);
    REP(i,0,n){
        cin >> coins[i];
    }
    unordered_set<int> possibleVals;
    for(int c : coins){
        vi newVals;
        for(int currVal : possibleVals){
            if(possibleVals.count(c + currVal) == 0){
                newVals.push_back(c + currVal);
            }
        }
        for(int newVal : newVals){
            possibleVals.insert(newVal);
        }
        possibleVals.insert(c);
    }
    vi res;
    for(int v : possibleVals){
        res.push_back(v);
    }
    sort(res.begin(), res.end());
    cout << res.size() << endl;
    for(int x : res){
        cout << x << " ";
    }
    cout << endl;
}
