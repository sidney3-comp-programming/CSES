#include <bits/stdc++.h>
using namespace std;

int dp[2][200001];
bool ready[200001];
int values[200001]

pair<int, int> backtrack(int node, vector<vector<int>> adj){
    if(ready[node]){
        return make_pair(dp[0][node], dp[1][node]);
    }

    int include = weights[node];
    int notInclude = 0;

    for(int child : adj[node]){
        pair<int, int> childRes = backtrack(child, adj);
        include += childRes.first;
        notInclude += max(childRes.first, childRes.second);
    }

    dp[0][node] = notInclude;
    dp[1][node] = include;
    ready[node] = true;

    return make_pair(notInclude, include);

}

int main(){
    int numNodes;
    vector<vector<int>> adj(numNodes);
    cin >> numNodes;
    int a,b;
    for(int i = 0; i < numNodes; i++){
        cin >> values[i];
    }
    for(int i = 1; i < numNodes; i++){
        cin >> a >> b;
        adj[a].push_back(b);
    }
    pair<int, int> res = backtrack(0, adj);
    return max(res.first, res.second);
}
