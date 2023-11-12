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

vi adj[100001];
int state[100001];
const int WHITE = 0, GREY = 1, BLACK = 2;

bool is_cycle_dfs(int curr){
    state[curr] = GREY;
    bool cycle_found = false;
    for(int next : adj[curr]){
        if(state[next] == WHITE)
            cycle_found = cycle_found || is_cycle_dfs(next);
        else if(state[next] == GREY)
            return true;
    }
    state[curr] = BLACK;
    return cycle_found;
}

void make_topo_dfs(int curr, vi& topo){
    state[curr] = BLACK;
    for(int next : adj[curr]){
        if(state[next] == WHITE)
            make_topo_dfs(next, topo);
    }
    topo.pb(curr);
}

vi make_topo(int n){
    vi topo;
    for(int i=1;i<=n;i++){
        if(state[i] == WHITE)
            make_topo_dfs(i, topo);
    }
    reverse(all(topo));
    return topo;
}

void solve(){
    int n,m;
    see(n,m);
    for(int i=0;i<m;i++){
        int s,t;
        see(s,t);
        adj[s].pb(t);
    }
    fill(begin(state), end(state), WHITE);
    for(int i=1;i<=n;i++){
        if(state[i]==WHITE && is_cycle_dfs(i)){
            putl("IMPOSSIBLE");
            return;
        }
    }
    fill(begin(state), end(state), WHITE);
    vi topo = make_topo(n);
    for(int x : topo) cout << x << " ";
    cout << endl;
}

int32_t main(){
    ios::sync_with_stdio(0); cin.tie(0);
    solve();
}