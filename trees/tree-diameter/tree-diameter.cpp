#include <bits/stdc++.h>
using namespace std;

#define MAX_SIZE 200001
#define REP(i,a,b) for(int i = a; i < b; i++)
#define pb push_back
typedef vector<int> vi;

vector<vi> Adj(MAX_SIZE);
int maxDiameter = 0;

bool cmp(int a, int b){
    return a > b;
}

int backtrack(int currNode, int prev){
    vi childLens;
    for(int child : Adj[currNode]){
        if(child == prev)
            continue;
        childLens.pb(backtrack(child, currNode));
    }
    sort(childLens.begin(), childLens.end(), cmp);
    int res = (childLens.size() > 0) ? (1 + childLens[0]) : 0;
    int diameter = (childLens.size() > 1) ? (2 + childLens[0] + childLens[1]) : res;
    maxDiameter = max(diameter, maxDiameter);

    return res;
}

int main(){
    int n, s, t;
    cin >> n;
    REP(i, 0, n - 1){
        cin >> s >> t;
        Adj[s].pb(t);
        Adj[t].pb(s);
    }
    backtrack(1, -1);
    cout << maxDiameter << endl;
}