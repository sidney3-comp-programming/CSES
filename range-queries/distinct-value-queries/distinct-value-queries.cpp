
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

struct BIT 
{
    vi T;
    BIT(const int n): T(n)
    {}
    int query(int i)
    {
        int res = 0;
        i++;
        while(i > 0)
        {
            res += T[i-1];
            i -= i&-i;
        }
        return res;
    }
    void update(int i, int chg)
    {
        i++;
        while(i <= T.sz())
        {
            T[i-1] += chg;
            i += i&-i;
        }
    }
};
void solve()
{
    int n,q;
    see(n,q);
    vi arr(n);
    f0r(i,n)
    {
        see(arr[i]);
    }
    vec<vii> queries(n);
    f0r(i,q)
    {
        int s,e;
        see(s,e);
        s--;
        e--;
        queries[s].pb(mp(e,i));
    }
    vi res(q);
    BIT b(n);
    map<int,int> last_index;
    r0f(i, n - 1)
    {
        if(last_index.find(arr[i]) != last_index.end())
        {
            b.update(last_index.at(arr[i]), -1);
        }
        last_index[arr[i]] = i;
        b.update(i, 1);
        for(auto [end, res_index] : queries[i])
        {
            res[res_index] = b.query(end);
        }
    }
    f0r(i,q)
    {
        putl(res[i]);
    }
}

int32_t main()
{
    ios::sync_with_stdio(0); cin.tie(0);
    solve();
}
