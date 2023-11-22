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
void solve()
{
    int n,q;
    see(n,q);
    vi arr(n);
    rep(i,0,n)
    {
        cin >> arr[i];
    }
    vi T(4*n);
    build(T,arr,1,1,n);
    rep(i,0,q)
    {
        int a,b;
        see(a,b);
        cout << query(T, 1, 1, n, a, b) << "\n";
    }   
}

int32_t main()
{
    ios::sync_with_stdio(0); cin.tie(0);
    solve();
}
