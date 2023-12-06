
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

string get_bin(int x)
{
    string res = "";
    r0f(i,20)
    {
        res += ((1<<i)&x) ? "1" : "0";
    }
    return res;
}
void solve()
{
    int n, x;
    cin >> n >> x;
    vi weights(n);
    f0r(i,n)
    {
        cin >> weights[i];
    }
    vii dp((1<<n), mp(0,0));
    rep(Subs, 1, (1<<n))
    {
        ii res = mp(n, 0);
        rep(p, 0, n)
        {
            int p_mask = (1<<p);
            if(!(p_mask & Subs))
            {
                continue;
            }
            ii prior_cost = dp[Subs ^ p_mask];
            ii new_cost = (prior_cost.S + weights[p] <= x) ?
                          mp(prior_cost.F, prior_cost.S + weights[p]) :
                          mp(prior_cost.F + 1, weights[p]);
            if(new_cost.F < res.F || new_cost.F == res.F && new_cost.S < res.S)
            {
                res = new_cost;
            }
        }
        dp[Subs] = res;
        /* cout << get_bin(Subs) << " " << res.F << " " << res.S << "\n"; */
    }
    ii final_res = dp.back();
    putl(final_res.F +( (final_res.S == 0) ? 0 : 1));
}

int32_t main()
{
    ios::sync_with_stdio(0); cin.tie(0);
    solve();
}
