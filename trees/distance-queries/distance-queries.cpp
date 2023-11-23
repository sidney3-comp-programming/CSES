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
#define vec vector
#define rep(i,a,b) for(int i = a; i < b; i++)
#define pb push_back
#define mp make_pair
#define F first
#define S second
#define all(v) (v).begin(), (v).end()
#define sz size
#define debug(x) cout << #x << ": " << x << endl;

const ll inf = LLONG_MAX;
const ld ep = 0.0000001;
const ld pi = acos(-1.0);
const ll md = 1000000007;
const int BIG = (INT_MAX-1)/2;
const int LOG = 20;

void fill_depth_and_parent_dfs(vec<vi>& adj, vi& parent, vi& depth, int curr, int prev, int curr_depth)
{
    depth[curr] = curr_depth;
    parent[curr] = prev;

    for(int next : adj[curr])
    {
        if(next == prev)
        {
            continue;
        }
        fill_depth_and_parent_dfs(adj, parent, depth, next, curr, curr_depth + 1);
    }
}
int jump(vec<vi>& jump_table, int curr, int steps)
{
    int res = curr;
    rep(p, 0, LOG)
    {
        if((1<<p) & steps)
        {
            res = jump_table[res][p];
        }
    }
    return res;
}
int LCA(vec<vi>& jump_table, vi& depth, int x, int y)
{
    if(depth[x] <= depth[y])
    {
        swap(x,y);
    }
     
    x = jump(jump_table, x, depth[x] - depth[y]);
    if(x == y)
    {
        return x;
    }
    for(int p = LOG - 1; p >= 0; p--)
    {
        int xp = jump_table[x][p], yp = jump_table[y][p];
        if(xp != yp)
        {
            x = xp;
            y = yp;
        }
    }
    return jump_table[x][0];
}
void solve()
{
    int n,q;
    see(n,q); 
    vec<vi> adj(n+1);
    rep(i,0,n-1)
    {
        int s,t;
        see(s,t);
        adj[s].pb(t);
        adj[t].pb(s);
    }
    vi parent(n+1), depth(n+1);
    fill_depth_and_parent_dfs(adj, parent, depth, 1, 0, 1);
    vec<vi> jump_table(n+1, vi(LOG, 0));
    rep(i,1,n+1)
    {
        jump_table[i][0] = parent[i];
    }
    rep(p, 1, LOG)
    {
        rep(i, 1, n+1)
        {
            jump_table[i][p] = jump_table[jump_table[i][p-1]][p-1];
        }
    }
    rep(i,0,q)
    {
        int x,y;
        see(x,y);
        int lca = LCA(jump_table, depth, x, y);
        putl(depth[x] + depth[y] - 2*depth[lca]);
    }
}

int32_t main()
{
    ios::sync_with_stdio(0); cin.tie(0);
    solve();
}
