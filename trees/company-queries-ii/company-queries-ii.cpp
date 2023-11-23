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

void fill_depth_dfs(vi& depth, const vec<vi>& adj, int curr, int prev, int curr_depth)
{
    depth[curr] = curr_depth;
    for(int next : adj[curr])
    {
        if(next == prev)
        {
            continue;
        }
        fill_depth_dfs(depth, adj, next, curr, curr_depth + 1);
    }
}
void solve()
{
    const int LOG = 19;
    int n,q;
    see(n,q);
    vec<vi> adj(n+1);
    vi parent(n+1);
    vi depth(n+1);
    rep(i,2,n+1)
    {
        int par;
        see(par);
        adj[par].pb(i);
        parent[i] = par;
    }
    fill_depth_dfs(depth, adj, 1, 0, 1);
    vec<vi> jump_table(n+1, vi(LOG, 0));
    rep(i,1,n+1)
    {
        jump_table[i][0] = parent[i];
    }
    rep(p,1,LOG)
    {
        rep(i,1,n+1)
        {
            jump_table[i][p] = jump_table[jump_table[i][p-1]][p-1];
        }
    }
    auto jump_fn = [](vec<vi>& jump_table, int curr, int steps)
    {
        int res = curr;
        rep(p,0,LOG)
        {
            if((1<<p) & steps)
            {
                res = jump_table[res][p];
            }
        }
        return res;
    };
    vi res;
    rep(i,0,q)
    {
        int a,b;
        see(a,b);
        int x = (depth[a] >= depth[b]) ? a : b;
        int y = (x == a) ? b : a;
        x = jump_fn(jump_table, x, depth[x] - depth[y]);
        if(x == y)
        {
            res.pb(x);
            continue;
        }
        for(int p = LOG-1; p >= 0; p--)
        {
            int xp=jump_table[x][p], yp = jump_table[y][p];
            if(xp != yp)
            {
                x= xp, y = yp;
            }
        }
        res.pb(jump_table[x][0]);
    }
    for(int x : res)
    {
        printf("%d\n", x);
    }
}

int32_t main()
{
    ios::sync_with_stdio(0); cin.tie(0);
    solve();
}
