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

int dp[200001];
bool ready[200001];
int dfs(int curr, vi& next){
    if(ready[curr]) {return dp[curr]; }
    dp[curr] = 1+dfs(next[curr], next);
    ready[curr]=true;
    return dp[curr];
}
const int WHITE=0,GREY=1,BLACK=2;
void solve(){
    int n; see(n);
    vi next(n+1);
    rep(i,1,n+1){
        cin>>next[i];
    }
    vec<int> label(n+1, WHITE);
    rep(p,1,n+1){
        vi path;
        int curr=p;
        while(label[curr] == WHITE){
            path.pb(curr);
            label[curr]=GREY;
            curr=next[curr];
        }
        if(label[curr] != GREY)
            continue;
        auto it = find(all(path),curr);
        int cycle_sz=distance(it, path.end());
        for(auto mit = path.begin(); mit != it; mit++){
            label[*mit]=BLACK;
        }
        for(; it != path.end(); it++){
            ready[*it]=true;
            dp   [*it]=cycle_sz;
            label[*it]=BLACK;
        }
    }
    for(int i=1;i<=n;i++)
        cout<<dfs(i,next)<<" ";
    cout<<"\n";


}

int32_t main(){
    ios::sync_with_stdio(0); cin.tie(0);
    solve();
}