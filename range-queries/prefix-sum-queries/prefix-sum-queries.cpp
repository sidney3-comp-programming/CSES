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
/*
const ll inf = LLONG_MAX;
const ld ep = 0.0000001;
const ld pi = acos(-1.0);
const ll md = 1000000007;
*/
const int BIG = (INT_MAX-1)/2;

int UPDATE = 1, QUERY = 2;
void build(vi& T, vi& pfx, int v, int tl, int tr)
{
    if(tl == tr)
    {
        T[v] = pfx[tl];
        return;
    }
    int tm = (tl + tr)/2;
    build(T, pfx, 2*v, tl, tm);
    build(T, pfx, 2*v + 1, tm + 1, tr);
    T[v] = max(T[2*v], T[2*v + 1]);
}
void update(vi& T, int inc, int l, int r, int v, int tl, int tr)
{
    if(tl == l && tr == r)
    {
        T[v] += inc;
        return;
    }
    if(l > r)
    {
        return;
    }
    int tm = (tl + tr)/2;
    update(T, inc, l, min(tm, r), 2*v, tl, tm);
    update(T, inc, max(l, tm + 1), r, 2*v+1, tm+1, tr);
    T[v] = max(T[2*v], T[2*v + 1]);
}
int query_max(vi& T, int l, int r, int v, int tl, int tr)
{
    if(tl == l && tr == r)
    {
        return T[v];
    }
    if(l > r)
    {
        return -BIG;
    }
    int tm = (tl + tr)/2;
    return max(query_max(T, l, min(r, tm), 2*v, tl, tm), query_max(T, max(l, tm+1), r, 2*v+1, tm+1, tr));
}
int query_idx(vi& T, int i, int v, int tl, int tr)
{
    if(tl == tr)
    {
        return T[v];
    }
    int tm = (tl + tr)/2;
    if(i <= tm)
    {
        return query_idx(T, i, 2*v, tl, tm);
    }
    else
    {
        return query_idx(T, i, 2*v+1, tm+1, tr);
    }
}
vi solve(const vi& arg_arr, const vec<vi>& queries)
{
    vi arr(arg_arr);
    int n = arr.sz();
    vi pfx(n);
    pfx[0] = arr[0];
    rep(i,1,n)
    {
        pfx[i] = arr[i] + pfx[i-1];
    }
    vi T(4*n);
    build(T,pfx,1,0,n-1);
    vi res;
    for(vi q : queries)
    {
        int Q_type = q[0];
        if(Q_type == UPDATE)
        {
            int idx = q[1], new_val = q[2];
            int diff = new_val - arr[idx - 1];
            arr[idx-1] = new_val;
            update(T, diff, idx - 1, n - 1, 1, 0, n - 1);
        }
        else if(Q_type == QUERY)
        {
            int l = q[1], r = q[2];
            int x = query_max(T, l - 1, r - 1, 1, 0, n - 1);
            if(l > 1)
            {
                x -= query_idx(T, l - 2, 1, 0, n-1);
            }
            res.pb(max(x,0));
        }
    }
    return res;
}

vi brute_force_solve(const vi& arr, const vec<vi>& queries)
{
    vi internal_arr(arr);
    auto make_pfx = [](vi& arr)
    {
        vi pfx(arr.sz());
        pfx[0] = arr[0];
        rep(i,1,arr.sz())
        {
            pfx[i] = pfx[i-1] + arr[i];
        }
        return pfx;
    };
    vi res;
    for(vi q : queries)
    {
        if(q[0] == UPDATE)
        {
            internal_arr[q[1]-1] = q[2];
        }
        else if(q[0] == QUERY)
        {
            vi pfx = make_pfx(internal_arr);
            int val = -BIG;
            rep(i, q[1]-1, q[2])
            {
                val = max(val, pfx[i]);
            }
            res.pb(val);
        }
    }
    return res;
}
int rand_range(int lo, int hi)
{
    static bool seeded = false;
    if(!seeded)
    {
        seeded = true;
        srand(0);
    }
    if(hi - lo + 1 == 0)
    {
        return hi;
    }
    return lo + (rand() % (hi - lo + 1));
}
void brute_force_test()
{
    const int TRIALS = 100, MAX_ARR_SZ = 100, MAX_QUERY_SZ=100, MIN_ELT = -100, MAX_ELT = 100;
    rep(_,0,TRIALS)
    {
       int arr_sz = rand_range(1, MAX_ARR_SZ);
       vi arr(arr_sz);
       int query_sz = rand_range(1, MAX_QUERY_SZ);
       vec<vi> queries(query_sz);
       rep(i,0,arr_sz)
       {
           arr[i] = rand_range(MIN_ELT, MAX_ELT);
       }
       rep(q,0,query_sz)
       {
           int Q_type = rand_range(1,2);
           if(Q_type == UPDATE)
           {
               int idx = rand_range(1, arr_sz);
               int new_val = rand_range(MIN_ELT, MAX_ELT);
               queries[q] = {Q_type, idx, new_val};
           }
           else if(Q_type == QUERY)
           {
               int hi = rand_range(1, arr_sz);
               int lo = rand_range(1, hi);
               queries[q] = {Q_type, lo, hi};
           }
       }
       vi exp = solve(arr, queries), seen = brute_force_solve(arr, queries);
       assert(exp.sz() == seen.sz());
       for(size_t i = 0; i < exp.sz(); i++)
       {
           assert(exp[i] == seen[i]);
           cout<<"s";
       }
    }
}
int32_t main()
{
    ios::sync_with_stdio(0); cin.tie(0);
    int n,q;
    see(n,q);
    vi arr(n);
    vec<vi> queries(q);
    rep(i,0,n)
    {
        cin >> arr[i];
    }
    rep(i,0,q)
    {
        int a,b,c;
        see(a,b,c);
        queries[i] = {a,b,c};
    }
    vi res = solve(arr, queries);
    for(int x : res)
    {
        putl(x);
    }
    // brute_force_test();
}
