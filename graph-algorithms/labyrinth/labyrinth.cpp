#include <bits/stdc++.h>
using namespace std;

template<typename... T>
void see(T&... args) { ((cin >> args), ...);}
template<typename... T>
void put(T&&... args) { ((cout << args << " "), ...);}
// #define ll long long
// #define ld long double
// #define ii pair<int, int>
// #define vi vector<int>
// #define vii vector<ii>
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
#define putl(x) cout << x << endl;
#define debug(x) cout << #x << ": " << x << endl;
#define int long long

const ll inf = LLONG_MAX;
const ld ep = 0.0000001;
const ld pi = acos(-1.0);
const ll md = 1000000007;

bool grid[1001][1001];
bool vis[1001][1001];
vii  adj[1001][1001];
vii curr_path;

const vii dirs = {
    {1,0},
    {-1,0},
    {0,1},
    {0,-1}
};
const map<ii, string> dir_names = {
    {{1,0}, "D"},
    {{-1,0}, "U"},
    {{0,1}, "R"},
    {{0,-1}, "L"}
};

void dfs(ii curr, const ii& end){
    if(curr.F == end.F && curr.S == end.S){
        putl(curr_path.sz());
        for(ii dir : curr_path){
            cout << dir_names.find(dir)->S;
        }            
        cout<<"\n";
        return;
    }
    for(ii next : adj[curr.F][curr.S]){
        curr_path.pb(next);
        dfs(mp(curr.F + next.F, curr.S + next.S), end);
        curr_path.pop_back();
    }
}

void solve(){
    int n,m;
    cin >> n >> m;
    bool grid[n][m];
    const char WALL = '#', START = 'A', END = 'B';
    ii start, end;
    for(int r=0;r<n;r++){
        for(int c =0;c<m;c++){
            char k;
            cin >> k;
            if(k == WALL){
                grid[r][c] = false;
                continue;
            }
            grid[r][c] = true;
            if(k == START)
                start = mp(r,c);
            if(k == END)
                end = mp(r,c);
        }
    }
    bool vis[n][m];
    memset(vis, false, sizeof(vis));
    vis[start.F][start.S] = true;
    deque<ii> q = {start};
    bool found = false;
    while(!q.empty()){
        ii curr = q.front();
        q.pop_front();
        if(curr.F == end.F && curr.S == end.S){
            found = true;
            break;
        }
        for(ii dir : dirs){
            ii next = mp(curr.F + dir.F, curr.S + dir.S);
            if(next.F >= 0 && next.F < n && next.S >= 0 && next.S < m && !vis[next.F][next.S] && grid[next.F][next.S]){
                adj[curr.F][curr.S].pb(dir);
                vis[next.F][next.S] = true;
                q.pb(next);
            }
        }
    }
    if(!found){
        putl("NO");
    }
    else{
        putl("YES");
        dfs(start, end);
    }

}

int32_t main(){
    ios::sync_with_stdio(0); cin.tie(0);
    solve();
}