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

using seg_node = tuple<vi,vi,int>;
void build(vec<seg_node>& T, vi& arr, int v, int tl, int tr)
{
}
int query(const vec<seg_node>& T, int l, int r, int v, int tl, int tr)
{

}
void solve()
{
    int n,q;
    see(n,q);
    
}

int32_t main()
{
    ios::sync_with_stdio(0); cin.tie(0);
    int t;
    see(t);
    while(t--)
        solve();
}
