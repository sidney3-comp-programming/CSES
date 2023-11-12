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

vi   adj[100001];
bool vis[100001];
int state[100001];
vi curr_path;
bool printed = false;

const int WHITE = 0, GREY = 1, BLACK = 2;
pair<int, bool> find_cycle_dfs(int curr){
    state[curr] = GREY;
    for(int next : adj[curr]){
        if(state[next] == GREY)
            return mp(curr, true);
        else if(state[next] == WHITE){
            pair<int, bool> next_status = find_cycle_dfs(next);
            if(next_status.S){
                return next_status;
            }
        }
    }
    state[curr] = BLACK;
    return mp(-1, false);
}
void print_cycle_dfs(int curr, int target){
    if(printed)
        return;
    state[curr] = GREY;
    curr_path.pb(curr);
    if(curr_path.sz() > 1 && curr == target){
        printed=true;
        putl(curr_path.sz());
        for(int x : curr_path) cout << x << " ";
        cout << endl;
    }
    else{
        for(int next : adj[curr]){
            if(state[next]!=WHITE && next != target)
                continue;
            print_cycle_dfs(next, target);
        }
    }
    state[curr]=BLACK;
    curr_path.pop_back();
}

void solve(){
    int n,m;
    see(n,m);

    fill(begin(vis), end(vis), false);
    for(int i=0;i<m;i++){
        int s,t;
        see(s,t);
        adj[s].pb(t);
    }

    int cycle_start = -1;
    for(int i=1;i<=n;i++){
        if(state[i] == WHITE){
            pair<int, bool> cycle_status = find_cycle_dfs(i);
            if(cycle_status.S){
                cycle_start=cycle_status.F;
                break;
            }
        }
    }
    if(cycle_start == -1){
        putl("IMPOSSIBLE");
        return;
    }
    fill(begin(state), end(state), WHITE);
    print_cycle_dfs(cycle_start, cycle_start);

}

int32_t main(){
    ios::sync_with_stdio(0); cin.tie(0);
    solve();
}