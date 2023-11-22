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
#define int long long

const ll inf = LLONG_MAX;
const ld ep = 0.0000001;
const ld pi = acos(-1.0);
const ll md = 1000000007;

int dp[201][2000001];
void solve(){
    int n,x;
    see(n,x);
    vi coins(n,0);
    rep(i,0,n){
        cin>>coins[i];
    }
    dp[0][0]=1;
    rep(coin,1,n+1){
        rep(cost,0,x+1){
            dp[coin][cost]=dp[coin-1][cost];
            if(coins[coin-1] <= cost){
                dp[coin][cost]+=dp[coin][cost-coins[coin-1]];
            }
            dp[coin][cost]%=md;
        }
    }
    putl(dp[n][x]);
}

int32_t main(){
    ios::sync_with_stdio(0); cin.tie(0);
    solve();
}