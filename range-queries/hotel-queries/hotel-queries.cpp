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

const ll inf = LLONG_MAX;
const ld ep = 0.0000001;
const ld pi = acos(-1.0);
const ll md = 1000000007;
const int BIG = (INT_MAX-1)/2;

void build(vi& T, vi& arr, int v, int tl, int tr)
{
    if(tl == tr)
    {
        T[v] = arr[tl];
    }
    else
    {
        int tm = (tl + tr)/2;
        build(T, arr, 2*v, tl, tm);
        build(T, arr, 2*v + 1, tm+1, tr);
        T[v] = max(T[2*v], T[2*v + 1]);
    }
}
void decrement(vi& T, int v, int tl, int tr, int i, int d)
{
    if(tl == tr)
    {
        T[v] -= d;
        return;
    }
    int tm = (tl + tr)/2;
    if(i <= tm)
    {
        decrement(T, 2*v, tl, tm, i, d);
    }
    else
    {
        decrement(T, 2*v + 1, tm + 1, tr, i, d);
    }
    T[v] = max(T[2*v], T[2*v + 1]);
}
int query(vi& T, int v, int tl, int tr, int l, int r)
{
    if(l > r)
    {
        return -BIG;
    }
    if(tl == l && tr == r)
    {
        return T[v];
    }
    int tm = (tl + tr)/2;
    return max
        (
         query(T, 2*v, tl, tm, l, min(r, tm)),
         query(T, 2*v+1, tm+1, tr, max(l, tm+1), r)
        );
}
void solve()
{
    int n,m;
    see(n,m);
    vi rooms(n);
    rep(i,0,n)
    {
        cin >> rooms[i];
    }
    vi T(4*n, -BIG);
    build(T, rooms, 1, 0, n - 1);
    rep(i,0,m)
    {
        int party_sz;
        see(party_sz);
        if(query(T, 1, 0, n-1, 0, n-1) < party_sz)
        {
            cout << 0 << " ";
            continue;
        }
        int l = 0, r = n-1, curr = n-1;
        while(l <= r)
        {
            int m = (l+r)/2;
            if(query(T, 1, 0, n-1, 0, m) >= party_sz)
            {
                curr = m;
                r = m - 1;
            }
            else
            {
                l = m + 1;
            }
        }
        cout << curr+1<<" ";
        decrement(T, 1, 0, n-1, curr, party_sz);
    }
    cout<<"\n";
}

int32_t main()
{
    ios::sync_with_stdio(0); cin.tie(0);
    solve();
}
