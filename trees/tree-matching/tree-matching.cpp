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

ii dfs(vec<vi>& adj, int curr, int prev)
{
    if(adj[curr].sz() == 1)
    {
        return make_pair(0, 1);
    }
    int non_include_sum = 0;
    int include_sum = 0;
    vii child_collection;
    for(int next : adj[curr])
    {
        if(next == prev)
        {
            continue;
        }
        ii child_data = dfs(adj, next, curr);
        non_include_sum += child_data.F;
        include_sum += child_data.S;
    }
    return make_pair(include_sum, 1 + non_include_sum);
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
    putl(dfs(adj, 1, 0).F);
}

int32_t main()
{
    ios::sync_with_stdio(0); cin.tie(0);
    solve();
}
