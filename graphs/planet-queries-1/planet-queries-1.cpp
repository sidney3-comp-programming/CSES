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

/*
Let succ[x][i] denote the successor of x, i away
*/
int succ_cache[200001][30];
bool     ready[200001][30];
int        adj[200001];

int succ(int node, int pow_2){
    if(pow_2 == 0){
        succ_cache[node][pow_2] = adj[node];
        return adj[node];
    }
    else if(ready[node][pow_2])
        return succ_cache[node][pow_2];
    ready[node][pow_2] = true;
    succ_cache[node][pow_2] = succ(succ(node, pow_2 - 1), pow_2 - 1);
    return succ_cache[node][pow_2];
}

void solve(){
    int n,q;
    see(n,q);
    for(int i=1;i<=n;i++){
        int next;
        see(next);
        adj[i]=next;
    }
    for(int j=1;j<=n;j++)
        for(int i=0;i<30;i++)
            succ(j,i);
    
    for(int i=0;i<q;i++){
        int start, steps;
        see(start, steps);
        int curr = start;
        for(int i=0;i<30;i++){
            if((1<<i)&steps)
                curr = succ_cache[curr][i];
        }
        putl(curr);
    }

}

int32_t main(){
    ios::sync_with_stdio(0); cin.tie(0);
    solve();
}