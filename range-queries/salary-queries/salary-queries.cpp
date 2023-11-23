#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
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
#define sz size
#define debug(x) cout << #x << ": " << x << endl;

struct range_counter_seg_tree
{
    public:
    range_counter_seg_tree(const int num_vals, const std::unordered_map<int,int>& init_val_counts);
    void update(int idx, int chg);
    int query(int l, int r);
    private:
    void update_recurse(int idx, int chg, int v, int tl, int tr);
    int query_recurse(int l, int r, int v, int tl, int tr);
    void build(const std::unordered_map<int,int>& init_val_counts, int v, int tl, int tr);
    std::vector<int> Tree;
    int num_vals;
};
std::unordered_map<int,int> compress(const std::vector<int>& vals);
std::vector<int> solve(std::vector<int> salaries, const std::vec<std::vector<int>>& queries);

const int CHG=1,CT=2;
range_counter_seg_tree::range_counter_seg_tree(const int num_vals, const std::unordered_map<int,int>& init_val_counts)
:Tree(4*num_vals, 0), num_vals(num_vals)
{
    build(init_val_counts, 1, 0, num_vals - 1);
}
void range_counter_seg_tree::build(const std::unordered_map<int,int>& init_val_counts, int v, int tl, int tr)
{
    if(tl == tr)
    {
        if(init_val_counts.count(tl) != 0)
        {
            Tree[v] = init_val_counts.at(tl);
        }
        return;
    }
    int tm = (tl + tr)/2;
    build(init_val_counts, 2*v, tl, tm);
    build(init_val_counts, 2*v+1, tm+1, tr);
    Tree[v] = Tree[2*v] + Tree[2*v+1];
}
void range_counter_seg_tree::update(int idx, int chg)
{
    update_recurse(idx, chg, 1, 0, num_vals - 1);
}
int range_counter_seg_tree::query(int l, int r)
{
    return query_recurse(l, r, 1, 0, num_vals - 1);
}
void range_counter_seg_tree::update_recurse(int idx, int chg, int v, int tl, int tr)
{
    if(tl == tr)
    {
        Tree[v] += chg;
        return;
    }
    int tm = (tl + tr)/2;
    if(idx <= tm)
    {
        update_recurse(idx, chg, 2*v, tl, tm);
    }
    else
    {
        update_recurse(idx, chg, 2*v + 1, tm + 1, tr);
    }
    Tree[v] = Tree[2*v] + Tree[2*v + 1];
}
int range_counter_seg_tree::query_recurse(int l, int r, int v, int tl, int tr)
{
    if(tl == l && tr == r)
    {
        return Tree[v];
    }
    if(l > r)
    {
        return 0;
    }
    int tm = (tl + tr)/2;
    return query_recurse(l, min(tm, r), 2*v, tl, tm) + query_recurse(max(tm+1, l), r, 2*v+1, tm+1,tr);
}
unordered_map<int,int> compress(const vi& vals)
{
    vi vals_cp(vals);
    sort(vals_cp.begin(), vals_cp.end());
    int ct = 0;
    unordered_map<int,int> val_to_index;
    for(int x : vals_cp) 
    {
        if(val_to_index.find(x) == val_to_index.end())
        {
            val_to_index[x] = ct++;
        }
    }
    return val_to_index;
}
vi solve(vi salaries, const vec<vi>& queries)
{
    const int CHG = 1, CT = 2;
    vi salary_archive; 
    for(int x : salaries)
    {
        salary_archive.pb(x);
    }
    for(vi v : queries)
    {
        if(v[0] == CHG)
        {
            salary_archive.pb(v[2]);
        }
        else if(v[0] == CT)
        {
            salary_archive.pb(v[1]);
            salary_archive.pb(v[2]);
        }
    }

    unordered_map<int,int> cd = compress(salary_archive);
    const int distinct_salaries = cd.sz();
    unordered_map<int,int> init_compressed_salaries;
    for(int x : salaries)
    {
        init_compressed_salaries[cd[x]]++;
    }
    range_counter_seg_tree st(distinct_salaries, init_compressed_salaries);
    vi res;
    for(vi q : queries)
    {
        int Q_type=q[0], a=q[1], b=q[2];
        if(Q_type == CT)
        {
            int l = min(cd[a], cd[b]), r = max(cd[a], cd[b]);
            res.pb(st.query(l, r));
        }
        else if(Q_type == CHG)
        {
           int old_idx = cd[salaries[a-1]];
           int new_idx = cd[b];
           salaries[a-1] = b;
           st.update(old_idx, -1);
           st.update(new_idx, 1);
        }
    }
    return res;
}
int32_t main()
{
    ios::sync_with_stdio(0); cin.tie(0);
    int n,q;
    cin >> n >> q;
    vi salaries(n);
    vec<vi> queries(q);
    rep(i,0,n)
    {
        cin >> salaries[i];
    }
    rep(i,0,q)
    {
        char Q_type;
        cin >> Q_type;
        int a,b;
        cin >> a >> b;
        if(Q_type == '?')
        {
            queries[i] = {2, a, b};
        }
        else
        {
            queries[i] = {1, a, b};
        }
    }
    vi res = solve(salaries, queries);
    for(int x : res)
    {
        putl(x);
    }
}
