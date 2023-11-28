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

void solve()
{
    const char TRAP = '*';
    int n;
    see(n);
    vec<vec<bool>> grid(n, vec<bool>(n, true));
    rep(i,0,n)
    {
        rep(j,0,n)
        {
            char c;
            cin >> c;
            grid[i][j] = (c != TRAP);
        }
    }
    vec<vi> dp(n, vi(n, 0));
    if(!grid[0][0])
    {
        putl("0");
        return;
    }
    dp[0][0] = 1;
    rep(i, 0, n)
    {
        rep(j, 0, n)
        {
            if(!grid[i][j])
            {
                continue;
            }
            if(i > 0)
            {
                dp[i][j] += dp[i-1][j];
            }
            if(j > 0)
            {
                dp[i][j] += dp[i][j-1];
            }
            dp[i][j] %= md;
        }
    }
    putl(dp[n-1][n-1]);
}

int32_t main()
{
    ios::sync_with_stdio(0); cin.tie(0);
    solve();
}
