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
#define int long long
const int MAX_NODES = 200001;
bool ready_below[MAX_NODES];
ii data_below[MAX_NODES];

bool ready_above[MAX_NODES];
ii data_above[MAX_NODES];
/*

Total number of paths into node i ->
distances from below, distances from above (and distances from above are equal to the tot)


*/
ii query_below(vec<vi>& adj, vi& parent, int node);
void fill_parent(vec<vi>& adj, vi& parent, int curr, int prev)
{
    parent[curr] = prev;
    for(int x : adj[curr])
    {
        if(x == prev)
        {
            continue;
        }
        fill_parent(adj, parent, x, curr);
    }
}
ii query_above(vec<vi>& adj, vi& parent, int node)
{
    if(ready_above[node])
    {
        return data_above[node];
    }
    if(!parent[node])
    {
        return mp(0,0);
    }
    ii parent_above_data = query_above(adj, parent, parent[node]);
    parent_above_data.F += parent_above_data.S;
    ii neighbor_data = query_below(adj, parent, parent[node]);
    ii local_data = query_below(adj, parent, node);
    neighbor_data.F -= local_data.F + local_data.S + 1;
    neighbor_data.S -= local_data.S + 1;
    neighbor_data.F += neighbor_data.S;
    ii res = make_pair(parent_above_data.F + neighbor_data.F, parent_above_data.S + neighbor_data.S);
    res.F++;
    res.S++;
    ready_above[node] = true;
    data_above[node] = res;
    return res;
}
ii query_below(vec<vi>& adj, vi& parent, int node)
{
    if(ready_below[node])
    {
        return data_below[node];
    }
    if(adj[node].sz() == 1 && node != 1) //leaf node
    {
        return mp(0,0);
    }
    ii local_data_below = mp(0,0);
    for(int child : adj[node])
    {
        if(child == parent[node])
        {
            continue;
        }
        ii child_data = query_below(adj, parent, child);
        local_data_below.S += 1 + child_data.S;
        local_data_below.F += 1 + child_data.S + child_data.F;
    }
    data_below[node] = local_data_below;
    ready_below[node] = true;
    return local_data_below;
}
void solve()
{
    int n;
    see(n);
    if(n == 1)
    {
        putl(0);
        return;
    }
    vec<vi> adj(n + 1);
    rep(i,0,n-1)
    {
        int s,t;
        see(s,t);
        adj[s].pb(t);
        adj[t].pb(s);
    }
    vi parent(n+1, 0);
    fill_parent(adj, parent, 1, 0);
    fill(begin(ready_below), end(ready_below), false);
    fill(begin(ready_above), end(ready_above), false);
    rep(i, 1, n + 1)
    {
        cout << query_below(adj, parent, i).F + query_above(adj, parent, i).F << " ";
    }
}

int32_t main()
{
    ios::sync_with_stdio(0); cin.tie(0);
    solve();
}
