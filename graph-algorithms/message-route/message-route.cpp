#include <bits/stdc++.h>
using namespace std;

template<typename... T>
void see(T&... args) { ((cin >> args), ...);}
template<typename... T>
void put(T&&... args) { ((cout << args << " "), ...);}
template<typename... T>
void putl(T&&... args) { ((cout << args << "\n"), ...);}
using ll = long long;
using ld = long double;
using ii = pair<int, int>;
using vi = vector<int>;
using vii = vector<pair<int, int>>;
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

vi adj       [100001];
vi pruned_adj[100001];
bool      vis[100001];
vi curr_path;

void dfs(int curr, int target){
    curr_path.pb(curr);
    if(curr == target){
        cout << curr_path.sz() << "\n";
        for(int z : curr_path)
            cout << z << " ";
        cout << "\n";
    }
    else{
        for(int next : pruned_adj[curr])
            dfs(next, target);
        
    }
    curr_path.pop_back();

}

void solve(){
    int n,m;
    cin >> n >> m;
    for(int i=0;i<m;i++){
        int s,t;
        cin >> s >> t;
        adj[s].pb(t);
        adj[t].pb(s);
    }
    memset(vis, false, sizeof(vis));
    bool found_route = false;
    vis[1] = true;
    deque<int> q = {1};
    while(!q.empty()){
        int curr = q.front();
        q.pop_front();
        if(curr == n){
            found_route = true;
            break;
        }
        for(int next : adj[curr]){
            if(!vis[next]){
                pruned_adj[curr].pb(next);
                q.pb               (next);
                vis[next] = true;
            }
        }
    }
    if(!found_route){
        cout << "IMPOSSIBLE\n";
    }
    else{
        dfs(1, n);
    }
}

int32_t main(){
    ios::sync_with_stdio(0); cin.tie(0);
    solve();
}