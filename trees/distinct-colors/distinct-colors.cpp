
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

class TraversalIndex
{
public:
    TraversalIndex(const vec<vi>& adj, const int num_nodes):
        tour_sz(0), tour_start(num_nodes), tour_end(num_nodes)
    {
       __dfs(adj, 0, -1);
    }
    int get_start(const int node)
    {
        return tour_start[node];
    }
    int get_end(const int node)
    {
        return tour_end[node];
    }
    int get_node(const int idx)
    {
        return idx_to_node[idx];
    }

private:
    int tour_sz;
    vi tour_start;
    vi tour_end;
    unordered_map<int,int> idx_to_node;
    void __dfs(const vec<vi>& adj, const int cur_node, const int prev_node)
    {
        tour_sz++;
        tour_start[cur_node] = tour_sz - 1;
        idx_to_node[tour_sz - 1] = cur_node;
        for(const int next_node : adj[cur_node])
        {
            if(next_node == prev_node)
            {
                continue;
            }
            __dfs(adj, next_node, cur_node);
        }
        tour_end[cur_node] = tour_sz - 1;
    }
};
class BIT
{
public:
    vi T;
    BIT(const int sz): T(sz) {}
    void update(int i, int chg)
    {
        i++;
        while(i <= T.sz())
        {
            T[i-1] += chg;
            i += i&-i;
        }
    }
    int query(int i)
    {
        i++;
        int res = 0;
        while(i > 0)
        {
            res += T[i-1];
            i -= i&-i;
        }
        return res;
    }
};
void solve()
{
    int n;
    see(n);
    vi node_val(n);
    vec<vi> adj(n);
    f0r(i,n)
    {
        see(node_val[i]);
    }
    f0r(_,n-1)
    {
        int s,t;
        see(s,t);
        s--;
        t--;
        adj[s].pb(t);
        adj[t].pb(s);
    }
    TraversalIndex ti(adj, n);
    vec<vii> queries(n);
    f0r(i,n)
    {
        queries[ti.get_start(i)].pb(mp(ti.get_end(i), i));
    }
    BIT b(n);
    map<int,int> last_seen;
    vi res(n);
    r0f(i, n-1)
    {
        int node_idx = ti.get_node(i);
        if(last_seen.find(node_val[node_idx]) != last_seen.end())
        {
            b.update(last_seen.at(node_val[node_idx]), -1);
        }
        last_seen[node_val[node_idx]] = i;
        b.update(i, 1);
        for(auto [end, query_index] : queries[i])
        {
            res[query_index] = b.query(end);
        }
    }
    f0r(i,n)
    {
        cout << res[i] << " ";
    }
    cout << "\n";
}

int32_t main()
{
    ios::sync_with_stdio(0); cin.tie(0);
    solve();
}
