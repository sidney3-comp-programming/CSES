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

vi maps_to[100001];
int     dp[100001];
bool ready[100001];

int dfs(int curr){
    if(curr == 1)
        return 1;
    if(ready[curr])
        return dp[curr];
    int res = 0;
    for(int prev : maps_to[curr]){
        res += dfs(prev);
        res %= md;
    }
    dp[curr]    = res;
    ready[curr] = true;
    return res%md;
}

void solve(){
    int n,m;
    see(n,m);
    for(int i=0;i<m;i++){
        int s,t;
        see(s,t);
        maps_to[t].pb(s);
    }
    fill(begin(ready), end(ready), false);
    fill(begin(dp),    end(dp),    0);
    int res = dfs(n);
    putl(res);
}

int32_t main(){
    ios::sync_with_stdio(0); cin.tie(0);
    solve();
}