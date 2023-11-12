#include <bits/stdc++.h>
using namespace std;

template<typename... T>
void see(T&... args) { ((cin >> args), ...);}
template<typename... T>
void put(T&&... args) { ((cout << args << " "), ...);}
using ll = long long;
using ld = long double;
using ii = pair<int, int>;
using vi = vector<int>;
using vii = vector<pair<int, int>>;
// #define ll long long
// #define ld long double
// #define ii pair<int, int>
// #define vi vector<int>
// #define vii vector<ii>
#define rep(i,a,b) for(int i = a; i < b; i++)
#define pb push_back
#define mp make_pair
#define F first
#define S second
#define all(v) (v).begin(), (v).end()
#define sz size
#define putl(x) cout << x << endl;
#define debug(x) cout << #x << ": " << x << endl;
// #define int long long

const ll inf = LLONG_MAX;
const ld ep = 0.0000001;
const ld pi = acos(-1.0);
const ll md = 1000000007;

bool vis [1001][1001];
bool grid[1001][1001];

bool in_grid(int r, int c, int n, int m){
    return (r>=0 && r <=n-1 && c >= 0 && c <= m - 1);
}
const vii dirs = {
    {1,0},
    {0,1},
    {-1,0},
    {0,-1}
};

void flood_fill(int r, int c, int n, int m){
    deque<ii> q = {mp(r,c)};
    vis[r][c] = true;
    while(!q.empty()){
        auto [curr_r, curr_c] = q.front();
        q.pop_front();
        for(ii next : dirs){
            int new_r = curr_r + next.F, new_c = curr_c + next.S;
            if(in_grid(new_r, new_c, n, m) && !vis[new_r][new_c] && grid[new_r][new_c]){
                vis[new_r][new_c] = true;
                q.pb(mp(new_r, new_c));
            }
        }
    }
}

void solve(){
    int n, m;
    cin >> n >> m;
    for(int r=0;r<n;r++){
        for(int c=0;c<m;c++){
            char k;
            cin >> k;
            grid[r][c] = (k == '.');
            vis[r][c] = false;
        }
    }
    int res = 0;
    for(int r=0;r<n;r++){
        for(int c=0;c<m;c++){
            if(grid[r][c] && !vis[r][c]){
                res++;
                flood_fill(r,c,n,m);
            }
        }
    }
    putl(res);
}

int32_t main(){
    ios::sync_with_stdio(0); cin.tie(0);
    solve();
}