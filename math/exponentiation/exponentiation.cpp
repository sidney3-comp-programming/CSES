#include <bits/stdc++.h>
#define REP(i,a,b) for(int i = a; i < b; i++)
#define pb push_back
#define mp make_pair
#define F first
#define S second
#define all(v) (v).begin(), (v).end()
#define sz size
#define putl(x) cout << x << endl;
#define put(x) cout << x << " ";
#define debug(x) cout << #x << ": " << x << endl;
#define int long long int
using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> ii;
typedef vector<pair<int,int>> vii;

static constexpr ll md = (ll) 1e9 + 7;

ll exp(ll x, ll p, ll md)
{
    if(p == 0)
    {
        return 1;
    }
    if(p & 1)
    {
        return (x*exp(x,p-1, md))%md;
    }
    ll res = exp(x,p/2,md);
    return (res*res)%md;
}

void solve(){
    ll a,b,c;
    cin >> a >> b >> c;
    ll p = exp(b,c,md-1);
    putl(exp(a,p,md));
}

int32_t main(){
    ios::sync_with_stdio(0); cin.tie(0);
    int t;
    cin >> t;
    while(t--){
        solve();
    }
}
