
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
    Lemma: we can travel between any two cities if and only if we can travel from every city to city 1
    and from city 1 to every city.

    => Clear
    <= Proof by contradiction 
*/
/*
Returns 0 if 1 can map to all nodes, otherwise returns the node that 1 cannot map to
*/
int check_maps_to(const vec<vi>& adj, const int src, const int num_nodes)
{
    vec<bool> vis(num_nodes + 1, false);
    vis[src] = true;
    queue<int> q; 
    q.push(src);
    while(!q.empty())
    {
        int curr = q.front();
        q.pop();
        for(int next : adj[curr])
        {
            if(vis[next])
            {
                continue;
            }
            vis[next] = true;
            q.push(next);
        }
    }
    for(int i = 1; i <= num_nodes; i++)
    {
        if(!vis[i])
        {
            return i;
        }
    }
    return 0;
}

void solve()
{
    int n, m;
    see(n,m);
    vec<vi> adj1(n + 1);
    vec<vi> adj2(n + 1);
    f0r(_,m)
    {
        int s,t;
        see(s,t);
        adj1[s].pb(t);
        adj2[t].pb(s);
    }
    int no_map_from;
    if((no_map_from = check_maps_to(adj2, 1, n)))
    {
        cout << "NO\n" << no_map_from << " " << 1 << "\n";
        return;
    }

    int no_map_to;
    if((no_map_to = check_maps_to(adj1, 1, n)))
    {
        cout << "NO\n" << 1 << " " << no_map_to << "\n"; 
    }
    cout << "YES\n";
}

int32_t main()
{
    ios::sync_with_stdio(0); cin.tie(0);
    solve();
}
