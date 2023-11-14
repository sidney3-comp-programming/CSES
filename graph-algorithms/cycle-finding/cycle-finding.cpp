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

const ll inf = 1LL<62;
const ld ep = 0.0000001;
const ld pi = acos(-1.0);
const ll md = 1000000007;

const int MAX_NODES = 2501, MAX_EDGES = 5001;

int dis[MAX_NODES];
int par[MAX_NODES];

void solve(){
    int n,m;
    see(n,m);

    vector<tuple<int,int,int>> edges;
    for(int i=0;i<m;i++){
        int s,t,w;
        see(s,t,w);
        edges.pb({s,t,w});
    }
    fill(begin(dis), end(dis), inf);
    fill(begin(par), end(par), -1);

    dis[1]=0;
    int f;
    for(int i=0;i<n+1;i++){
        f = 0;
        for(auto [s,t,w] : edges){
            if(dis[s] + w < dis[t]){
                f = t;
                par[t]=s;
                dis[t]=w+dis[s];
            }
        }
    }
    if(!f){
        putl("NO");
        return;
    }
    putl("YES");
    vi  cyc;
    int curr = f;
    for(int i=0;i<n;i++)f=par[f];
    for(int x=f;;x=par[x]){
        cyc.pb(x);
        if(x==f && cyc.sz()>1)
            break;
    }
            
    for(int j=cyc.sz()-1;j>=0;j--)
        cout << cyc[j] << " ";
        return;
        

}

int32_t main(){
    ios::sync_with_stdio(0); cin.tie(0);
    solve();
}