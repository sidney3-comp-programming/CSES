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

const ll inf = LLONG_MAX;
const ld ep = 0.0000001;
const ld pi = acos(-1.0);
const ll md = 1000000007;

int vis[100005], dis[100005];
vii adj[100005];
void solve(){
    int n,m; see(n,m);
    rep(i,0,m){
        int u,v,w; see(u,v,w);
        adj[u].pb({v,w});
    }
    //dijkstra
    rep(i,2,n+1) dis[i]=inf;
    priority_queue<ii,vii,greater<ii>> q;
    q.push({0,1});
    while(!q.empty()){
        int u = q.top().S; q.pop();
        if (vis[u]) continue;
        vis[u]=1;
        for (auto [v,w] : adj[u]){
            if (dis[v]>dis[u]+w){
                dis[v] = dis[u]+w;
                q.push({dis[v],v});
            }
        }
    }
    rep(i,1,n+1) put(dis[i]);


}

int32_t main(){
    ios::sync_with_stdio(0); cin.tie(0);
    solve();
}