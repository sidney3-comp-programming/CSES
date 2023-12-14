
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
const ll inf = 1LL<<52;
const ld ep = 0.0000001;
const ld pi = acos(-1.0);
const ll md = 1000000007;
const int BIG = (INT_MAX-1)/2;


class union_set 
{
public:
    union_set(int num_vals): parent(num_vals + 1), cmp_size(num_vals + 1)
    {
        for(int i = 1; i <= num_vals; i++)
        {
            parent[i] = i;
            cmp_size[i] = 1;
        }
    };
    int get_parent(int node)
    {
        if(parent[node] == node)
        {
            return node;
        }
        int compression = get_parent(parent[node]);
        parent[node] = compression;
        return compression;
    }
    bool join(int node1, int node2)
    {
        int node1_parent = get_parent(node1), node2_parent = get_parent(node2);
        if(node1_parent == node2_parent)
        {
            return false;
        }

        if(cmp_size[node1_parent] < cmp_size[node2_parent])
        {
            swap(node1_parent, node2_parent);
        }
        parent[node2_parent] = node1_parent;
        cmp_size[node2_parent] += cmp_size[node1_parent];
        return true;
    }
private:
    vector<int> parent;
    vector<int> cmp_size;
};
void __second_dfs(const vec<pair<vi,vi>>& adj, vi& vis, union_set& us, int curr_node)
{
    vis[curr_node] = true;
    for(int next : adj[curr_node].S)
    {
        if(vis[next])
        {
            continue;
        }
        us.join(curr_node, next);
        __second_dfs(adj, vis, us, next);
    }
}
void __first_dfs(const vec<pair<vi,vi>>& adj, vi& vis, vi& stck, int curr_node)
{
    vis[curr_node] = true;
    for(int next : adj[curr_node].F)
    {
        if(vis[next])
        {
            continue;
        }
        __first_dfs(adj,vis,stck,next);
    }
    stck.pb(curr_node);
}
void solve()
{
    int n,m;
    see(n,m);
    vec<pair<vi,vi>> adj(n+1);
    f0r(_,m)
    {
        int s,t;
        see(s,t);
        adj[s].F.pb(t);
        adj[t].S.pb(s);
    }
    vi vis(n+1, false);
    vi stck;
    rep(node,1,n+1)
    {
        if(!vis[node])
        {
            __first_dfs(adj,vis,stck, node);
        }
    }
    fill(all(vis), false);
    union_set us(n);
    while(!stck.empty())
    {
        if(!vis[stck.back()])
        {
            __second_dfs(adj,vis,us,stck.back());
        }
        stck.pop_back();
    }
    set<int> added_components;
    map<int,int> component_num;
    rep(node, 1, n + 1)
    {
        if(added_components.count(us.get_parent(node)) == 0)
        {
            added_components.insert(us.get_parent(node));
            component_num[us.get_parent(node)] = added_components.sz();
        }
    }
    cout << added_components.sz() << "\n";

    rep(node, 1, n + 1)
    {
        cout << component_num[us.get_parent(node)] << " ";
    }

}

int32_t main()
{
    ios::sync_with_stdio(0); cin.tie(0);
    solve();
}
