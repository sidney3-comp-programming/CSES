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
const ll md = 1000000000007;

int fast_pow(int x, int p){
    if(p==0){
        return 1;
    }
    if(p&1){
        return (x*fast_pow(x,p-1))%md;
    }
    else{
        int res=fast_pow(x,p/2);
        return (res*res)%md;
    }
}
int pos_mod(int x){
    int res=x%md;
    if(res<0)
        res+=md;
    return res;
}
void solve(){
    string s,p;
    see(s,p);
    int n=s.sz(),m=p.sz();

    if(m > n){
        cout<<"0\n";
        return;
    }
    auto char_val = [](char c){
        return ((int) c) - ((int) 'a');
    };
    auto str_equality = [](const string& p, const string &s, int i){
        if(i+p.sz() > s.sz()){
            return false;
        }
        rep(k,0,p.sz()){
            if(p[k] != s[i+k]){
                return false;
            }
        }
        return true;
    };
    int curr_hash=0;
    int exp_hash =0;
    rep(i,0,m){
        exp_hash+=fast_pow(26,m-i-1)*char_val(p[i]);
        exp_hash=pos_mod(exp_hash);
    }
    rep(i,0,m){
        curr_hash+=fast_pow(26,m-i-1)*char_val(s[i]);
        curr_hash=pos_mod(curr_hash);
    }
    int res=0;
    if(exp_hash==curr_hash&&(n>1000 || str_equality(p,s,0)))
        res++;
    rep(l,1,n-m+1){
        curr_hash = (curr_hash - fast_pow(26,m-1)*char_val(s[l-1]))*26 + char_val(s[l+m-1]);
        curr_hash = pos_mod(curr_hash);
        //below is a cheat to the problem (probabilistic)
        if(exp_hash==curr_hash&&(n>1000 || str_equality(p,s,l)))
            res++;
    }
    putl(res);
}

int32_t main(){
    ios::sync_with_stdio(0); cin.tie(0);
    solve();
}