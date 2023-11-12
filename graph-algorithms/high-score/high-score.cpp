#include <bits/stdc++.h>
using namespace std;

template<typename... T>
void see(T&... args) { ((cin >> args), ...);}
template<typename... T>
void put(T&&... args) { ((cout << args << " "), ...);}
#define ll long long
#define ld long double
#define ii pair<int, int>
#define vi vector<int>
#define vii vector<ii>
#define rep(i,a,b) for(int i = a; i < b; i++)
#define pb push_back
#define mp make_pair
#define F first
#define S second
#define all(v) (v).begin(), (v).end()
#define sz size
#define putl(x) cout << x << endl;
#define debug(x) cout << #x << ": " << x << endl;
#define int long long
#define a aa

const ll inf = LLONG_MAX;
const ld ep = 0.0000001;
const ld pi = acos(-1.0);
const ll md = 1000000007;

int dp[2501];
bool vis[2501];
vi adj[2501];

void solve(){
    int n,m;
    cin >> n >> m;
    memset(vis, false, sizeof(vis));
    dp[1] = 0;
    vis[1] = true;
    vector<vi> edges;

    for(int i=0;i<m;i++){
        int s,t,w; cin >> s >> t >> w;
        edges.pb({s,t,w});
        adj[s].pb(t);
    }
    for(int i = 0; i < n; i++){
        for(vi edge : edges){
            int s = edge[0], t = edge[1], w = edge[2];
            if(!vis[s])
                continue;
            else if(!vis[t]){
                vis[t] = true;
                dp[t] = w + dp[s];
            }
            else{
                dp[t] = max(dp[t], w + dp[s]);
            }
        }
    }
    int a = 5;
    debug(a);
    deque<int> cyclic_nodes;
    for(vi edge : edges){
        int s = edge[0], t = edge[1], w = edge[2];
        if(vis[s] && dp[t] < w + dp[s])
            cyclic_nodes.pb(t);
    }
    set<int> visited_nodes;
    while(!cyclic_nodes.empty()){
        int curr = cyclic_nodes.front(); cyclic_nodes.pop_front();
        if(curr == n){
            putl(-1);
            return;
        }
        for(int next : adj[curr]){
            if(visited_nodes.count(next) == 0){
                visited_nodes.insert(next);
                cyclic_nodes.pb(next);
            }
        }
    }
    putl(dp[n]);
}

int32_t main(){
    ios::sync_with_stdio(0); cin.tie(0);
    solve();
}