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

int pos_mod(int x){
    return(x%md + md)%md;
}
int fast_pow(int x, int p){
    if(p==0)
        return 1;
    if(p&1)
        return (x*fast_pow(x,p-1))%md;
    else{
        int res=fast_pow(x,p/2);
        return (res*res)%md;
    }
}
bool dp[1000001];
bool ready[1000001];
void solve(){
    string s;
    see   (s);
    int n=s.sz();
    int exp_hash=0;
    auto char_val=[](char c){
        return (int)c - (int)'a' + 1;
    };
    unordered_map<int,int> prefix_hash;
    rep(i,0,n){
        exp_hash=pos_mod(26*exp_hash + char_val(s[i]));
        prefix_hash[i+1]=exp_hash;
    }
    int base=0;
    vi res;
    rep(period_len,1,n+1){
        if(ready[period_len]){
            if(dp[period_len]){
                res.pb(period_len);
            }
            continue;
        }
        if(period_len>1 && s[period_len-1]==s[period_len-2]){
            
        }
        base=prefix_hash[period_len];
        int full_hash=base;
        bool skipped=false;
        for(int cp=1;cp<n/period_len;cp++){
            if(full_hash != prefix_hash[cp*period_len]){
                skipped=true;
                break;
            }
            full_hash=pos_mod(full_hash*fast_pow(26,period_len)+base);
        }
        if(skipped)
            continue;
        int partial_len=n%period_len;
        full_hash=pos_mod(fast_pow(26,partial_len)*full_hash + prefix_hash[partial_len]);
        if(full_hash==exp_hash){
            res.pb(period_len);
            for(int k=period_len; k <= n; k += period_len){
                ready[k]=true;
                dp[k]=true;
            }
        }
    }
    for(int x : res){
        cout<<x<<" ";
    }
    cout<<"\n";
}

int32_t main(){
    ios::sync_with_stdio(0); cin.tie(0);
    solve();
}