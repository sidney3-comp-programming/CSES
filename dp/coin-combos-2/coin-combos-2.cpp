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
dp(i,j) = dp()
*/
void solve()
{
    int n,x;
    see(n,x);
    vi coins(n);
    rep(i,0,n)
    {
        cin >> coins[i];
    }
    vi state(x + 1, 0);
    state[0] = 1;
    rep(coin_num, 0, n)
    {
        vi new_state(x + 1, 0);
        new_state[0] = 1;
        rep(val, 1, x + 1)
        {
            new_state[val] = state[val];
            if(coins[coin_num] <= val)
            {
                new_state[val] += new_state[val - coins[coin_num]];
            }
            new_state[val] %= md;
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
