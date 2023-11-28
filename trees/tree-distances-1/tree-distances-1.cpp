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
const int LOG = 20;

void fill_depth_and_parent(const vec<vi>& adj, vi& depth, vi& parent, int curr, int prev, int curr_depth)
{
    depth[curr] = curr_depth;
    parent[curr] = prev;
    for(int next : adj[curr])
    {
        if(next == prev)
        {
            continue;
        }
        fill_depth_and_parent(adj, depth, parent, next, curr, curr_depth + 1);
    }
}
int jump(const vec<vi>& up, int curr, int steps)
{ 
    int res = curr;
    rep(p,0,LOG)
    {
        if((1<<p) & steps)
        {
            res = up[res][p];
        }
    }
    return res;
}
int lca(const vec<vi>& up, const vi& depth, int x, int y)
{
    if(depth[y] >= depth[x])
    {
        swap(x,y);
    }
    x = jump(up, x, depth[x] - depth[y]);
    if(x == y)
    {
        return x;
    }
    for(int p = LOG-1; p >= 0; p--)
    {
        int xp = up[x][p], yp = up[y][p];
        if(xp != yp)
        {
            x = xp, y = yp;
        }
    }
    return up[x][0];
}
int dis(const vec<vi>& up, const vi& depth, int x, int y)
{
    int LCA = lca(up, depth, x, y);
    return depth[x] + depth[y] - 2*depth[LCA];
}
int furthest_node(vec<vi>& adj, int s)
{
    vec<bool> vis(adj.sz(), false);
    vis[s] = true;
    vi q = {s};
    while(!q.empty())
    {
        vi next_q;
        for(int curr : q)
        {
            for(int next : adj[curr])
            {
                if(vis[next])
                {
                    continue;
                }
                vis[next] = true;
                next_q.pb(next);
            }
        }
        if(next_q.sz() == 0)
        {
            return q.front();
        }
        q.swap(next_q);
    }
    return -1;
}
void solve()
{
    int n;
    see(n);
    vec<vi> adj(n+1);
    rep(i,0,n-1)
    {
        int s,t;
        see(s,t);
        adj[s].pb(t);
        adj[t].pb(s);
    }
    vi parent(n+1, 0), depth(n+1, 0);
    fill_depth_and_parent(adj, depth, parent, 1, 0, 1);
    vec<vi> up(n+1, vi(LOG + 1, 0));
    rep(i,1,n+1)
    {
        up[i][0] = parent[i];
    }
    rep(p,1,LOG)
    {
        rep(i,1,n+1)
        {
            up[i][p] = up[up[i][p-1]][p-1];
        }
    }
    int diameter1 = furthest_node(adj, 1);
    int diameter2 = furthest_node(adj, diameter1);
    rep(i, 1, n+1)
    {
        printf("%d ",max(dis(up, depth, i, diameter1), dis(up, depth, i, diameter2)));
    }
}

int32_t main()
{
    ios::sync_with_stdio(0); cin.tie(0);
    solve();
}
