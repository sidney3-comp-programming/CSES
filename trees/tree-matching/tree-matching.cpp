
#include <bits/stdc++.h>
using namespace std;

template<typename... T>
void see(T&... args) { ((cin >> args), ...);}
template<typename... T>
void put(T&&... args) { ((cout << args << " "), ...);}
template<typename... T>
void putl(T&&... args) { ((cout << args << "\n"), ...);}
int ciel(int a, int b) {return ceil(static_cast<double>(a) / static_cast<double>(b));}
#define ll long long
#define ld long double
#define ii pair<int, int>
#define vi vector<int>
#define vii vector<ii>
#define vec vector
#define rep(i,a,b) for(int i = a; i < b; i++)
#define f0r(i,a) for(int i = 0; i < a; i++)
#define r0f(i,a) for(int i = a; i >= 0; i--)
#define pb push_back
#define mp make_pair
#define F first
#define S second
#define all(v) (v).begin(), (v).end()
#define sz size
#define debug(x) cout << #x << ": " << x << endl;

const string albet{"abcdefghijklmnopqrstuvwxyz"};
const ll inf = LLONG_MAX;
const ld ep = 0.0000001;
const ld pi = acos(-1.0);
const ll md = 1000000007;
const int BIG = (INT_MAX-1)/2;

/*
    dp_1(v) := maximum matching on subtree of v assuming that we don't take any of the edges directory below v
    dp_2(v) := maximum matching on subtree of v assuming we are allowed to take exactly one of the edges below v
*/
static constexpr int MAX_NODES = 200000;
array<ii, MAX_NODES> dp;
array<bool, MAX_NODES> ready;
ii backtrack(const vec<vi>& adj, int curr_node, int prev)
{
    if(ready[curr_node])
    {
        return dp[curr_node];
    }
    int no_include = 0;
    for(int child : adj[curr_node])
    {
        if(child == prev)
        {
            continue;
        }
        no_include += backtrack(adj, child, curr_node).S; 
    }
    int include = 0;
    for(int child : adj[curr_node])
    {
        if(child == prev)
        {
            continue;
        }
        ii child_data = backtrack(adj, child, curr_node);
        include = max(include, no_include - child_data.S + child_data.F + 1);
    }
    ready[curr_node] = true;
    ii res = mp(no_include, max(include, no_include));
    dp[curr_node] = res;
    return res;
}
void solve()
{
    int n;
    see(n);
    vec<vi> adj(n);
    f0r(_,n-1)
    {
        int s,t;
        see(s,t);
        adj[--t].pb(--s);
        adj[s].pb(t);
    }
    fill(all(ready), false);
    putl(max(backtrack(adj, 0, -1).F, backtrack(adj, 0, -1).S));
}

int32_t main()
{
    ios::sync_with_stdio(0); cin.tie(0);
    solve();
}
