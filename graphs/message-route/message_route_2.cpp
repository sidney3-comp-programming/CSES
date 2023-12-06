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

vi adj    [100001];
int parent[100001];
bool vis  [100001];

void print_path(int start, int end){
    vi path = {end};
    int curr = end;

    while(curr != start){
        curr = parent[curr];
        path.pb(curr);
    }
    putl(path.sz());
    for(auto it = path.rbegin(); it != path.rend(); it++){
        cout << *it << " ";
    }
    cout << "\n";
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
    fill(begin(vis), end(vis), false);
    vis[1] = true;
    int TARGET = n;
    queue<int> q;
    q.push(1);
    while(!q.empty()){
        int curr = q.front();
        q.pop();
        if(curr == TARGET){
            print_path(1,n);
            return;
        }
        for(int next : adj[curr]){
            if(!vis[next]){
                q.push(next);
                parent[next] = curr;
                vis   [next] = true;
            }
        }
    }
    putl("IMPOSSIBLE");
}

int32_t main(){
    ios::sync_with_stdio(0); cin.tie(0);
    solve();
}