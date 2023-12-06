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
#define f0r(i,a) for(int i = 0; i < a; i++)
#define r0f(i,a) for(int i = a - 1; i >= 0; i--)
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
const int BIG = (INT_MAX-1)/2;

/*
   we need to store for each node
   A) it's starting index within the Euler tour
   B) the ending index of its child within the Euler tour.

*/
void build(vi& T, vi& arr, int v, int tl, int tr)
{
    if(tl == tr)
    {
        T[v] = arr[tl];
        return;
    }
    int tm = (tl+tr)/2;
    build(T, arr, 2*v,tl, tm);
    build(T, arr, 2*v+1, tm+1, tr);
    T[v] = T[2*v] + T[2*v+1];
}
int query(vi& T, int v, int tl, int tr, int l, int r)
{
    if(tl == l && tr == r)
    {
        return T[v];
    }
    if(l > r)
    {
        return 0;
    }
    int tm = (tl + tr)/2;
    return query(T, 2*v, tl, tm, l, min(tm, r)) + query(T, 2*v+1, tm+1, tr, max(tm+1, l), r);
}
void update(vi& T, int v, int tl, int tr, int i, int x)
{
    if(tl == tr)
    {
        T[v] = x;
        return;
    }
    int tm = (tl + tr)/2;
    if(i <= tm)
    {
        update(T, 2*v, tl, tm, i, x);
    }
    else
    {
        update(T, 2*v+1, tm+1, tr, i, x);
    }
    T[v] = T[2*v]+ T[2*v+1];
}
vi euler;
void dfs(const vec<vi>& adj, const vi& node_val, vii& node_data, int curr, int prev)
{
    euler.pb(node_val[curr]);
    int euler_start = euler.sz() - 1;
    for(int next : adj[curr])
    {
        if(next == prev)
        {
            continue;
        }
        dfs(adj, node_val, node_data, next, curr);
    }
    int euler_end = euler.sz() - 1;
    node_data[curr] = make_pair(euler_start, euler_end);
}
void solve()
{
    const int CHANGE_VAL = 1, QUERY_NODE = 2;
    int n,q;
    see(n,q);
    vi node_val(n+1);
    vii node_data(n+1);
    vec<vi> adj(n+1);
    f0r(i,n)
    {
        cin >> node_val[i +1];
    }
    f0r(i,n-1)
    {
        int s,t;
        see(s,t);
        adj[s].pb(t);
        adj[t].pb(s);
    }
    dfs(adj,node_val, node_data, 1, 0);
    /*  */
    /* for(int x : euler) */
    /* { */
    /*     cout << x << " "; */
    /* } */
    /* cout << "\n"; */
    /* for(ii d : node_data) */
    /* { */
    /*     cout << d.F << " " << d.S << ","; */
    /* } */
    /* cout << "\n"; */
    vi T(4*n);
    build(T, euler, 1, 0, n-1);
    f0r(i,q)
    {
        int Q_type;
        see(Q_type);
        if(Q_type == CHANGE_VAL)
        {
            int node,new_val;
            see(node,new_val);
            int node_index = node_data[node].F;
            update(T, 1, 0, n - 1, node_index, new_val);
        }
        else if(Q_type == QUERY_NODE)
        {
            int node;
            see(node);
            auto [node_start, node_end] = node_data[node];
            /* cout << node_start << " " << node_end << "\n"; */
            putl(query(T, 1, 0, n - 1, node_start, node_end));
        }
    }
   
}

int32_t main()
{
    ios::sync_with_stdio(0); cin.tie(0);
    solve();
}
