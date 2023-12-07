
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
#define int long long

const string albet{"abcdefghijklmnopqrstuvwxyz"};
const ll inf = LLONG_MAX;
const ld ep = 0.0000001;
const ld pi = acos(-1.0);
const ll md = 1000000007;
const int BIG = (INT_MAX-1)/2;

class tree_indexer 
{
public:
    tree_indexer(const vec<vi>& adj, const int _num_nodes):
        cur_tour_sz(0), num_nodes(_num_nodes), tour_start(num_nodes + 1), tour_end(num_nodes + 1)
    {
        __dfs(adj, 1, 0);
    }
    int get_start(const int node)
    {
        assert(1 <= node && node <= num_nodes);
        return tour_start[node];
    }
    int get_end(const int node)
    {
        assert(1 <= node && node <= num_nodes);
        return tour_end[node];
    }
private:
    int cur_tour_sz;
    int num_nodes;
    vi  tour_start;
    vi  tour_end;
    void __dfs(const vec<vi>& adj, const int cur_node, const int prev_node)
    {
        cur_tour_sz++;
        tour_start[cur_node] = cur_tour_sz-1;
        for(const int next : adj[cur_node])
        {
            if(next == prev_node)
            {
                continue;
            }
            __dfs(adj, next, cur_node);
        }
        tour_end[cur_node] = cur_tour_sz-1;
    }
};
class seg_tree
{
public:
    seg_tree(const int _num_nodes):
        num_nodes(_num_nodes), T(num_nodes*4)
    {}
    void update(int l, int r, int chg)
    {
        assert(l <= r);
        assert(l >= 0 && r < num_nodes);
        __update(1, 0, num_nodes - 1, l, r, chg);
    }
    int query(int i)
    {
        assert(0 <= i && i < num_nodes);
        return __query(1, 0, num_nodes - 1, i);
    }
private:
    int num_nodes;
    vi T;
    int __query(int v, int tl, int tr, int i)
    {
        if(tl == tr)
        {
            return T[v];
        }
        int tm = (tl + tr)/2;
        if(i <= tm)
        {
            return T[v] + __query(2*v, tl, tm, i);
        }
        else
        {
            return T[v] + __query(2*v+1, tm + 1, tr, i);
        }
    }
    void __update(int v, int tl, int tr, int l, int r, int x)
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
        int tm = (tl + tr)/2;
        __update(2*v, tl, tm, l, min(r, tm), x);
        __update(2*v + 1, tm + 1, tr, max(l, tm + 1), r, x);
    }
};
void solve()
{
    const int UPDATE = 1, QUERY = 2;
    int n,q;
    see(n,q);

    vi vals(n+1);
    rep(node, 1, n+1)
    {
        see(vals[node]);
    }
    vec<vi> adj(n + 1);
    f0r(_, n-1)
    {
        int s,t;
        see(s,t);
        adj[s].pb(t);
        adj[t].pb(s);
    }
    tree_indexer ti(adj, n);
    seg_tree st(n);
    rep(node, 1, n +1)
    {
        st.update(ti.get_start(node), ti.get_end(node), vals[node]);
    }
    f0r(_,q)
    {
        int Q_type;
        see(Q_type);
        if(Q_type == UPDATE)
        {
            int node, new_val;
            see(node, new_val);
            int val_diff = new_val - vals[node];
            st.update(ti.get_start(node), ti.get_end(node), val_diff);
            vals[node] = new_val;
        }
        else if(Q_type == QUERY)
        {
            int node;
            see(node);
            putl(st.query(ti.get_start(node)));
        }
    }
}

int32_t main()
{
    ios::sync_with_stdio(0); cin.tie(0);
    solve();
}
