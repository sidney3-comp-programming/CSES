#include <bits/stdc++.h>
using namespace std;
#define REP(i,a,b) for(int i = a; i < b; i++)
#define pb push_back
typedef vector<int> vi;

int res[200001];
bool visited[200001];

int dfs(vector<vi> &tree, int currNode){
    int children = 0;
    for(int child : tree[currNode]){
        children += 1 + dfs(tree, child);
    }
    res[currNode] = children;
    visited[currNode] = true;
    return children;
}

int main(){
    int n, c;
    cin >> n;
    vector<vi> tree(n);
    REP(i, 1, n){
        cin >> c;
        tree[c-1].pb(i);
    }
    REP(i, 0, n){
        if(!visited[i]){
            dfs(tree, i);
        }
        cout << res[i] << " ";
    }
    cout << endl;
    
}