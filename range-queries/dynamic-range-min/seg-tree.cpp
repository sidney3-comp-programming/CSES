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
#define int long long
const ll inf = LLONG_MAX;
const ld ep = 0.0000001;
const ld pi = acos(-1.0);
const ll md = 1000000007;

void build(vi& T, vi& arr, int v, int tl, int tr)
{
    if(tl == tr)
    {
        T[v] = arr[tl-1];
        return;
    }
    int m = (tl + tr)/2;
    build(T, arr, 2*v, tl, m);
    build(T, arr, 2*v + 1, m+1, tr);
    T[v] = min(T[2*v], T[2*v + 1]);
}
int query(vi& T, int v, int tl, int tr, int l, int r)
{
    if(tl == l && tr == r)
    {
        return T[v];
    }
    if(l > r)
    {
        return inf; 
    }
    int m = (tl+tr)/2;
    return min(query(T, 2*v, tl, m, l, min(r, m)), query(T, 2*v+1, m+1,tr,max(l,m+1), r));
}
void update(vi& T, int x, int i, int v, int tl, int tr)
{
    if(tl == tr)
    {
        T[v] = x;
        return;
    }
    int m = (tl + tr)/2;
    if(i <= m)
    {
        update(T, x, i, 2*v, tl, m);
    }
    else
    {
        update(T, x, i, 2*v+1, m+1, tr);
    }
    T[v] = min(T[2*v], T[2*v + 1]);
}
vi solve (vi& arr, vec<vi>& requests)
{
    int n = arr.sz();
    vi T(4*n, 1'000'000'007);
    build(T,arr,1,1,n);
    vi res;
    for(vi q : requests)
    {
        int q_type = q[0], a = q[1],b = q[2];
        if(q_type == 1)
        {
           update(T, b, a, 1, 1, n);
        }
        else if(q_type == 2)
        {
            res.pb(query(T, 1, 1,n,a,b));
        }
    }
    return res;
}
vi brute_force_solve(vi& arr, vec<vi>& requests)
{
    vi internal(arr);
    vi res_arr;
    for(vi q : requests)
    {
        int q_type=q[0], a=q[1], b = q[2];
        if(q_type == 1)
        {
            internal[a-1] = b;
        }
        else if(q_type == 2)
        {
            int res=1'000'000'007;
            rep(i,a-1,b)
            {
                res=min(res,internal[i]);
            }
            res_arr.pb(res);
        }
    }
    return res_arr;
}
int rand_range(int lo, int hi)
{
    if(hi - lo + 1 == 0)
    {
       return hi; 
    }
    return lo + (rand() % (hi - lo + 1));
}
void test_impl()
{
    const int MAX_SZ=1000, MAX_VAL=1000,REQUESTS=100,TRIALS=100;
    srand(0);
    rep(i,0,TRIALS)
    {
        int arr_sz=rand_range(1,MAX_SZ);
        vi arr(arr_sz);
        rep(i,0,arr_sz)
        {
            arr[i] = rand_range(0, MAX_VAL);
        }
        vec<vi> reqs(REQUESTS);
        rep(i,0,REQUESTS)
        {
            vi request;
            int req_type = rand_range(1,2);
            request.pb(req_type);
            if(req_type == 1)
            {
                int pos = rand_range(1, arr_sz);
                int val = rand_range(1, MAX_VAL);
                request.pb(pos);
                request.pb(val);
            }
            else if (req_type == 2)
            {
                int hi_pos = rand_range(1, arr_sz);
                int lo_pos = rand_range(1, hi_pos);
                request.pb(lo_pos);
                request.pb(hi_pos);
            }
            reqs[i] = request;
        }
        vi expected_response = brute_force_solve(arr, reqs);
        vi seen_response     = solve(arr, reqs);
        assert(expected_response.sz() == seen_response.sz());
        rep(i,0,(int) seen_response.sz())
        {
            assert(expected_response[i] == seen_response[i]);
        }

    }
}
int32_t main()
{
    ios::sync_with_stdio(0); cin.tie(0);
    test_impl();
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
        int q_type,a,b;
        see(q_type,a,b);
        queries[i] = {q_type, a, b};
    }
    vi res = solve(arr, queries);
    for(int x : res)
    {
        cout << x << "\n";
    }
}
