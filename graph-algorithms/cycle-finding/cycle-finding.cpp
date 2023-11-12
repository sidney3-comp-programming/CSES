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

const int MAX_NODES = 2501;
const int WHITE=1,GREY=2,BLACK=3;

int state[MAX_NODES];
int   dis[MAX_NODES];
vii   adj[MAX_NODES];

vi curr_path;
bool printed = false;

void dfs(int curr_node, int path_sum){
    if(printed)
        return;
    
    state[curr_node] = GREY;
    dis  [curr_node] = path_sum;
    curr_path.pb(curr_node);

    for(auto [next, edge_weight] : adj[curr_node]){
        if(state[next] == GREY && path_sum + edge_weight < dis[next]){
            printed = true;
            putl("YES");
            int cycle_start = -1;
            for(int i=0;i<curr_path.sz();i++)
                if(curr_path[i] == next)
                    cycle_start=i;
            for(int j=cycle_start;j<curr_path.sz();j++)
                cout << curr_path[j] << " ";
            cout << next << " ";
        }
        else if(state[next] == WHITE){
            dfs(next, path_sum + edge_weight);
        }
    }

    state[curr_node] = BLACK;
    curr_path.pop_back();
}

void solve(){
    int n,m;
    see(n,m);
    for(int i=0;i<m;i++){
        int s,t,w;
        see(s,t,w);
        adj[s].pb(mp(t,w));
    }
   
    for(int i=1;i<=n;i++){
        fill(begin(state), end(state), WHITE);
        fill(begin(dis), end(dis), inf);     
        dfs(i, 0);
    }
    if(!printed)
        putl("NO");
}

int32_t main(){
    ios::sync_with_stdio(0); cin.tie(0);
    solve();
}