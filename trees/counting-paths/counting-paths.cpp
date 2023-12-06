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

const ll inf = LLONG_MAX;
const ld ep = 0.0000001;
const ld pi = acos(-1.0);
const ll md = 1000000007;
const int BIG = (INT_MAX-1)/2;

void update(vi& T, int v, int tl, int tr, int l, int r, int x)
{
    if(tl == l && tr == r)
    {
        T[v] += x;
        return;
    }
    if(l > r)
    {
        return;
    }
    int tm = (tl+tr)/2;
    update(T, 2*v, tl, tm, l, min(r, tm), x);
    update(T, 2*v+1, tm+1, tr, max(l, tm+1), r, x);
}
int query(vi& T, int v, int tl, int tr, int i)
{
    if(tl == tr)
    {
        return T[v];
    }
    int tm = (tl + tr)/2;
    if(i <= tm)
    {
        return T[v] + query(T, 2*v, tl, tm, i);     
    }
    else
    {
        return T[v] + query(T, 2*v+1, tm+1, tr, i);
    }
}
void dfs(const vec<vi>& adj, vi& euler, vii& node_data, int curr, int prev)
{
    euler.pb(curr);
    int euler_start = euler.sz() - 1;
    for(int next : adj[curr])
    {
        if(next == prev)
        {
            continue;
        }
        dfs(adj, euler, node_data, next, curr);
    }
    int euler_end = euler.sz() - 1;
    node_data[curr] = mp(euler_start, euler_end);
}
void solve()
{
    int n,m;
    see(n,m);
    vii node_data;
    vi euler;
    vec<vi> adj(n+1);
    f0r(i,n-1)
    {
        int s,t;
        see(s,t);
        adj[s].pb(t);
        adj[t].pb(s);
    }



}

int32_t main()
{
    ios::sync_with_stdio(0); cin.tie(0);
    solve();
}
