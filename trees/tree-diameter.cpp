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

ii furthest_node(const vec<vi>& adj, int root)
{
    vi q = {root};
    int dis = 0;
    vec<bool> vis(adj.sz() + 1, false);
    vis[root] = true;
    while(!q.empty())
    {
        vi next;
        for(int x : q)
        {
            if(vis[x])
            {
                continue;
            }
            next.pb(x);
            vis[x] = true;
        }
        if(next.sz() == 0)
        {
            return mp(q.front(), dis);
        }
        dis++;
        q.swap(next);
    }
    return mp(-1,-1);
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
    ii diameter1 = furthest_node(adj, 1);
    ii diameter2 = furthest_node(adj, diameter1.F);
    putl(diameter2.S);
}

int32_t main()
{
    ios::sync_with_stdio(0); cin.tie(0);
    solve();
}
