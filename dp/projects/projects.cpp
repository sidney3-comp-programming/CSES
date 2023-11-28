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
#define r0f(i,a) for(int i = a - 1; i >= 0; i--)
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

void solve()
{
    int n;
    see(n);
    vec<array<int,3>> projects(n);
    f0r(i,n)
    {
        int start, end, reward;
        see(start, end, reward);
        projects[i] = {start, end, reward};
    }
    sort(all(projects), [](const array<int,3>& a, const array<int,3>& b){
        return a[1] < b[1];
    });
    vi dp(n);
    dp[0] = projects[0][2];
    rep(i, 1, n)
    {
        auto [start, end, reward] = projects[i];
        dp[i] = dp[i-1];
        int l = 0, r = i, found = 0;
        while(l <= r)
        {
            int m = (l+r)/2;
            if(start > projects[m][1])   
            {
                found = m;
                l = m + 1;
            }
            else
            {
                r = m - 1;
            }
        }
        dp[i] = max(dp[i], reward + ((found>0) ? dp[found-1] : 0));
    }
    putl(dp.back());
}

int32_t main()
{
    ios::sync_with_stdio(0); cin.tie(0);
    solve();
}
