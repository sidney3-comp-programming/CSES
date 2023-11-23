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

void preprocess_dfs(vi& depth, vi& parent, vec<vi>& adj, int curr, int prev, int curr_depth)
{   
    parent[curr] = prev;
    depth[curr] = curr_depth;
    for(int next : adj[curr])
    {
        if(next == prev)
        {
            continue;
        }
        preprocess_dfs(depth, parent, adj, next, curr, curr_depth+1);
    }
}
int get_farthest(vec<vi>& adj, int root)
{
    vi q = {root};
    vec<bool> vis(adj.sz() + 1);
    while(!q.empty())
    {
        vi next_q;
        for(int next : q)
        {
            if(vis[next])
            {
                continue;
            }
            next_q.pb(next);
        }
        if(next_q.sz() == 0)
        {
            return q.front();
        }
        q.swap(next_q);
    }
    return -1;
}
int LCA(auto& jump_fn, vi& depth, int a, int b)
{
    int x = (depth[a] >= depth[b]) ? a : b;
    int y = (x == a) ? b : a;
    x = jump_fn(x, abs(depth[a] - depth[b]));
    int l = 0, r = depth[x], res = depth[x];
    while(l <= r)
    {
        int m = (l+r)/2;
        if(jump_fn(x, m) == jump_fn(y,m))
        {
            res = m;
            r = m - 1;
        }
        else
        {
            l = m + 1;
        }
    }
    return res;
}
void solve()
{
    int n;
    see(n);
    vec<vi> adj(n);
    rep(i,0,n-1)
    {
        int s,t;
        see(s,t);
        adj[s].pb(t);
        adj[t].pb(s);
    }
    vi depth(n+1);
    vi parent(n+1); 
    preprocess_dfs(depth, parent, adj, 1, 0, 1);
    vec<vi> jump_table(n+1, vi(25, 0));
    rep(i,1,n+1)
    {
        jump_table[i][0] = parent[i];
    }
    rep(p,1,25)
    {
        rep(i,1,n+1)
        {
            jump_table[i][p] = jump_table[jump_table[i][p-1]][p-1];
        }
    }
    auto jump_fn = [](vec<vi>& jump_table, int curr, int steps)
    {
        int res = curr;
        rep(p,0,25)
        {
            if((1<<p) & steps)
            {
                res = jump_table[res][p]; 
            }
        }
        return res;
    };
    int diameter1 = get_farthest(adj, 1);
    int diameter2 = get_farthest(adj, diameter1);
    rep(i,1,n+1)
    {
       int d1 = depth[i] + depth[diameter1] - 2*depth[LCA(jump_fn, depth, i, diameter1)];
       int d2 = depth[i] + depth[diameter2] - 2*depth[LCA(jump_fn, depth, i, diameter2)];
       cout << max(d1,d2) << " \n";
    }

}

int32_t main()
{
    ios::sync_with_stdio(0); cin.tie(0);
    int t;
    see(t);
    while(t--)
        solve();
}
