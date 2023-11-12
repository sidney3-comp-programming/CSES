#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> ii;

#define REP(i,a,b) for(int i = a; i < b; i++)
#define pb push_back
#define mp make_pair
#define f first
#define s second
#define all(v) (v).begin(), (v).end()
#define sz(v) (int)(v).size()
#define debug(x) cout << #x << ": " << x << endl;

vi         currPath;
vector<vi> adj     (100001);
bool       visited [100001];

vi dfs(int node, int prev){
    if(visited[node]){
        currPath.pb(node);
        return currPath;
    }
    visited[node] = true;
    currPath.pb(node);
    for(int next : adj[node]){
        if(next == prev) continue;
        vi res = dfs(next, node);
        if(res.size() > 0){
            return res;
        }
    }
    currPath.pop_back();
    vi emptyList;
    return emptyList;

}

int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    int n,m;
    cin >> n >> m;

    REP(i,0,m){
        int a,b;
        cin >> a >> b;
        adj[a].pb(b);
        adj[b].pb(a);
    }
    REP(j,1,n + 1){
        if(visited[j]) continue;
        vi res = dfs(j, -1);
        if(res.size() > 0){
            int p = 0;
            while(res[p] != res.back()){
                p++;
            }
            cout << res.size() - p << endl;
            while(p < res.size()){
                cout << res[p] << " ";
                p++;
            }
            cout << endl;

            return 0;
        }
    }
    cout << "IMPOSSIBLE" << endl;
}