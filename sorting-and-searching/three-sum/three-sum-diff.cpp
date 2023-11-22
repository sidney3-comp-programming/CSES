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


void solve(){
    int n,x;
    see(n,x);
    vi nums(n);
    rep(i,0,n){
        cin>>nums[i];
    }

    map<int,vi> freq;
    rep(i,0,n){
        freq[nums[i]].pb(i);
    }
    rep(i,0,n){
        rep(j,0,i){
            if(i==j || (x-(nums[i]+nums[j]))<0 || freq.find((x-(nums[i]+nums[j]))) == freq.end()){
                continue;
            }
            for(int k : freq[x-(nums[i]+nums[j])]){
                if(k != i && k != j){
                    cout << i+1<<" "<<j+1<<" "<<k+1<<"\n";
                    return;
                }
            }
        }
    }
    putl("IMPOSSIBLE");
}

int32_t main(){
    ios::sync_with_stdio(0); cin.tie(0);
    solve();
}