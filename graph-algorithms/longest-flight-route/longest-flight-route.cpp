#include <bits/stdc++.h>
using namespace std;

template<typename... T>
void see(T&... args) { ((cin >> args), ...);}
template<typename... T>
void put(T&&... args) { ((cout << args << " "), ...);}
template<typename... T>
void putl(T&&... args) { ((cout << args << "\n"), ...);}
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
#define debug(x) cout << #x << ": " << x << endl;
#define int long long

const ll inf = LLONG_MAX;
const ld ep = 0.0000001;
const ld pi = acos(-1.0);
const ll md = 1000000007;

vi pruned_adj[100001];
vi        adj[100001];
int vis_capac[100001];
int vis_count[100001];
int    parent[100001];
bool      vis[100001];

void solve(){
    int n,m;
    see(n,m);
    for(int i=0;i<m;i++){
        int s,t;
        see(s,t);
        adj[s].pb(t);
    }
    vis[1] = true;
    deque<int> q = {1};
    while(!q.empty()){
        int curr = q.front();
        q.pop_front();
        for(int next : adj[curr]){
            pruned_adj[curr].pb(next);
            vis_capac[next]++;
            if(!vis[next])
                q.pb(next);
            vis[next] = true;
        }
    }
    fill(begin(vis), end(vis), false);
    q.pb(1);
    vis[1] = true;
    while(!q.empty()){
        int curr = q.front();
        q.pop_front();
        for(int next : pruned_adj[curr]){
            if(vis[next])
                continue;
            vis_count[next]++;
            if(vis_count[next] >= vis_capac[next]){
                vis[curr] = true;
                parent[next] = curr;
                q.pb(next);
            }
        }
    }
    if(!parent[n]){
        putl("IMPOSSIBLE");
        return;
    }
    int curr = n;
    vi path = {curr};
    while(curr != 1){
        curr = parent[curr];
        path.pb(curr);
    }
    reverse(all(path));
    cout << path.sz() << "\n";
    for(int x : path) cout << x << " ";
    cout << endl;
}

int32_t main(){
    ios::sync_with_stdio(0); cin.tie(0);
    solve();
}
