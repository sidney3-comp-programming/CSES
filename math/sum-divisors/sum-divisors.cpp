
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

void solve()
{
    ll n, res = 0;
    see(n);
    ll r = sqrt(n);
    unordered_set<int> divisors;
    for(int composite = 1; composite <= r; composite++)
    {
        ll c1 = composite, c2 = n / composite;
        if(divisors.find(c1) == divisors.end())
        {
            ll freq = floor(n / c1);
            res += c1 * freq;
            res %= md;
            put(c1,freq,"\n");
            divisors.insert(c1);
        }
        if(divisors.find(c2) == divisors.end())
        {
            ll freq = floor(n / c2);
            res += c2 * freq;
            res %= md;
            put(c2,freq,"\n");
            divisors.insert(c2);
        }
    }
    putl(res);
}

int32_t main()
{
    ios::sync_with_stdio(0); cin.tie(0);
    solve();
}
