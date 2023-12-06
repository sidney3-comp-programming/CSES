
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

class LowestCommonAncestor
{
public:
    LowestCommonAncestor(const int _num_nodes, const vi& _parent, const vi& _depth):
        num_nodes(_num_nodes), depth(_depth), parent(_parent), jump_table(LOG, vi(_num_nodes + 1))
    {
        rep(i,1,_num_nodes + 1)
        {
            jump_table[0][i] = _parent[i];
        }
        rep(pow,1,LOG)
        {
            rep(i,1,_num_nodes + 1)
            {
                jump_table[pow][i] = jump_table[pow-1][jump_table[pow-1][i]];
            }
        }
    }
    int operator()(int node1, int node2)
    {
        assert(1 <= min(node1,node2) && max(node1,node2) <= num_nodes);
        if(depth[node1] <= depth[node2])
        {
            swap(node1, node2);
        }
        node1 = jump(node1, depth[node1] - depth[node2]);
        if(node1 == node2)
        {
            return node1;
        }
        r0f(i, LOG - 1)
        {
           int node1P = jump_table[i][node1];
           int node2P = jump_table[i][node2];
           if(node1P != node2P)
           {
               node1 = node1P;
               node2 = node2P;
           }
        }
        return jump_table[0][node1];
    }
private:
    static constexpr int LOG = 25;
    int num_nodes;
    vi parent;
    vi depth;
    vec<vi> jump_table;
    int jump(int start_node, int steps)
    {
        int cur = start_node;
        f0r(i, LOG)
        {
            if((1<<i) & steps)
            {
                cur = jump_table[i][cur];
            }
        }
        return cur;
    }
};
void __make_depth(const vec<vi>& adj, vi& depth, const int cur_node, const int cur_depth)
{
    depth[cur_node] = cur_depth;
    for(const int next : adj[cur_node])
    {
        __make_depth(adj, depth, next, cur_depth + 1);
    }
}
void solve()
{
    int n,q;
    see(n,q);

    vi parent(n+1, 0);
    vi depth(n+1, 0);
    vec<vi> adj(n+1);
    rep(i,2,n+1)
    {
        int p;
        see(p);
        adj[p].pb(i);
        parent[i] = p;
    }
    __make_depth(adj, depth, 1, 0);
    LowestCommonAncestor lca(n, parent, depth);
    f0r(_,q)
    {
        int a,b;
        see(a,b);
        putl(lca(a,b));
    }
}

int32_t main()
{
    ios::sync_with_stdio(0); cin.tie(0);
    solve();
}
