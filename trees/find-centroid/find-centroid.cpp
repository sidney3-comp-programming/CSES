
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

class SubtreeSz
{
public:
    SubtreeSz(const vec<vi>& adj, const int _num_nodes):
        num_nodes(_num_nodes), subtree_sz(_num_nodes)
    {
        __dfs(adj, 0, -1);
    }
    int operator()(const int cur_node)
    {
        assert(0 <= cur_node && cur_node <= num_nodes - 1);
        return subtree_sz[cur_node];
    }
private:
    int num_nodes;
    vi subtree_sz;
    int __dfs(const vec<vi>& adj, const int cur_node, const int prev_node)
    {
        int subtree_nodes = 1;
        for(const int next_node : adj[cur_node])
        {
            if(next_node == prev_node)
            {
                continue;
            }
            subtree_nodes += __dfs(adj, next_node, cur_node);
        }
        subtree_sz[cur_node] = subtree_nodes;
        return subtree_nodes;
    }
};
void solve()
{
    int n;
    see(n);
    vec<vi> adj(n);
    f0r(_,n-1)
    {
        int s,t;
        see(s,t);
        s--;
        t--;
        adj[s].pb(t);
        adj[t].pb(s);
    }
    SubtreeSz s_sz(adj, n);
    f0r(i,n)
    {
        /* cout << "subtree size: " << i << " " << s_sz(i) << "\n"; */
    }
    int max_child_sz = BIG;
    int curr_node = 0;
    int prev_node = -1;
    while(max_child_sz > floor(n/2))
    {
        ii best_child = mp(-1, -1);
        for(int next_node : adj[curr_node])
        {
            if(next_node == prev_node)
            {
                continue;
            }
            if(s_sz(next_node) > best_child.S)
            {
                best_child = mp(next_node, s_sz(next_node));
            }
        }
        max_child_sz = best_child.S;
        if(max_child_sz > floor(n/2))
        {
            int tmp = curr_node;
            curr_node = best_child.F;
            prev_node = tmp;
        }
    }
    putl(curr_node + 1);
}

int32_t main()
{
    ios::sync_with_stdio(0); cin.tie(0);
    solve();
}
