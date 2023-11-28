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
#define f0r(i,a) for(int i = 0; i < a; i++)
#define r0f(i,a) for(int i = a; i >= 0; i--)
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

/*
say dp(i,j) = the number of changes required to make s[i:], t[j:] equal.

Then we have a few choices:
delete the ith character from either. And that is functionally the same as adding the other. If they are equal we can differ up.

*/
void solve()
{
    string s, t;
    see(s,t);
    if(s.sz() < t.sz())
    {
        swap(s,t);
    }
    int n = s.sz(), m = t.sz();
    vec<vi> dp(n + 1, vi(m + 1, BIG));
    f0r(i,n + 1)
    {
        dp[i][m] = n - i;
    }
    f0r(i,m + 1)
    {
        dp[n][i] = m - i;
    }
    r0f(i,n - 1)
    {
        r0f(j,m - 1)
        {
           dp[i][j] = min({1 + dp[i + 1][j], 1 + dp[i][j + 1], 1 + dp[i + 1][j + 1]}); 
           if(s[i] == t[j])
           {
               dp[i][j] = min(dp[i][j], dp[i+1][j+1]);
           }
        }
    }
    putl(dp[0][0]);
}

int32_t main()
{
    ios::sync_with_stdio(0); cin.tie(0);
    solve();
}
