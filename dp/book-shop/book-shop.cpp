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

/*
dp(i,j) := the maximum number of pages we can buy with $i and books[0:j]
dp(0,0) = 0

dp(i,j) = max(dp(i, j - 1), dp(i - price[j], j))
*/
const int MAX_BUDGET = 100001;
void solve()
{
    int n,x;
    see(n,x);
    vi price(n);
    vi pages(n);
    rep(i,0,n)
    {
        cin >> price[i];
    }
    rep(i,0,n)
    {
        cin >> pages[i];
    }
    vi state(MAX_BUDGET, 0);
    rep(i,0,n)
    {
        vi new_state(MAX_BUDGET, 0);
        rep(val, 1, x + 1)
        {
            new_state[val] = state[val];
            if(price[i] <= val)
            {
                new_state[val] = max(new_state[val], state[val - price[i]] + pages[i]);
            }
        }
        state = new_state;
    }
    putl(state[x]);
}

int32_t main()
{
    ios::sync_with_stdio(0); cin.tie(0);
    solve();
}
