#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> ii;
typedef vector<pair<int,int>> vii;

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
static constexpr int MOD = (int) 1e9 + 7;

int exp(int a, int b){
    if(b == 0){
        return 1;
    }
    if(b&1){
        return a*exp(a, b-1) % MOD;
    }
    else{
        int res =  exp(a, b / 2) % MOD;
        return res*res % MOD;
    }
}

void solve(){
    int a,b,c;
    cin >> a >> b >> c;
    cout << exp(a,exp(b,c)) << endl;
}

int32_t main(){
    ios::sync_with_stdio(0); cin.tie(0);
    int t;
    cin >> t;
    while(t--){
        solve();
    }
}