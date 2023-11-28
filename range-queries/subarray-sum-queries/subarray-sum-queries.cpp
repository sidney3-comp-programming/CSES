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
const int BIG = (INT_MAX-1)/2;
/*
Store a bunch of data for each range:

store left flush sum, right flush sum, total sum, and best sum

*/
const int FLUSH_LEFT = 0, FLUSH_RIGHT = 1, TOTAL_SUM = 2, BEST_SUM = 3;

void update(vec<array<int, 4>>& T, int v, int tl, int tr, int idx, int new_val)
{
    if(tl == tr)
    {
        T[v] = {new_val, new_val, new_val, new_val};
        return;
    }
    int tm = (tl + tr)/2;
    if(idx <= tm)
    {
        update(T, 2*v, tl, tm, idx, new_val);
    }
    else
    {
        update(T, 2*v+1, tm+1, tr, idx, new_val);
    }
    T[v][TOTAL_SUM] = T[2*v][TOTAL_SUM] + T[2*v + 1][TOTAL_SUM];
    T[v][FLUSH_LEFT] = max(T[2*v][FLUSH_LEFT], T[2*v][TOTAL_SUM] + T[2*v + 1][FLUSH_LEFT]);
    T[v][FLUSH_RIGHT] = max(T[2*v + 1][FLUSH_RIGHT], T[2*v + 1][TOTAL_SUM] + T[2*v][FLUSH_RIGHT]);
    T[v][BEST_SUM] = max({T[2*v][BEST_SUM], T[2*v+1][BEST_SUM], T[2*v][FLUSH_RIGHT] + T[2*v + 1][FLUSH_LEFT]});
}
void build(vec<array<int,4>>& T, vi& arr, int v, int tl, int tr)
{
    if(tl == tr)
    {
        T[v] = {arr[tl], arr[tl], arr[tl], arr[tl]};
        return;
    }
    int tm = (tl + tr)/2;
    build(T, arr, 2*v, tl, tm);
    build(T, arr, 2*v + 1, tm+1, tr);
    T[v][TOTAL_SUM] = T[2*v][TOTAL_SUM] + T[2*v + 1][TOTAL_SUM];
    T[v][FLUSH_LEFT] = max(T[2*v][FLUSH_LEFT], T[2*v][TOTAL_SUM] + T[2*v + 1][FLUSH_LEFT]);
    T[v][FLUSH_RIGHT] = max(T[2*v + 1][FLUSH_RIGHT], T[2*v + 1][TOTAL_SUM] + T[2*v][FLUSH_RIGHT]);
    T[v][BEST_SUM] = max({T[2*v][BEST_SUM], T[2*v+1][BEST_SUM], T[2*v][FLUSH_RIGHT] + T[2*v + 1][FLUSH_LEFT]});
}
void solve()
{
    int n, m;
    see(n, m);
    vi arr(n);
    rep(i,0,n)
    {
        cin >> arr[i];
    }
    vec<array<int,4>> T(4*n, {0,0,0,0});
    build(T, arr, 1, 0, n - 1);
    rep(i,0,m)
    {
        int idx,x;
        see(idx,x);
        update(T, 1, 0, n - 1, idx - 1, x);
        putl(max(T[1][BEST_SUM], (ll)0));
    }
}

int32_t main()
{
    ios::sync_with_stdio(0); cin.tie(0);
    solve();
}
