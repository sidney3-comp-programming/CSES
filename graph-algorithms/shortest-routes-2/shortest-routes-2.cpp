#include <bits/stdc++.h>
using namespace std;

template<typename... T>
void see(T&... args) { ((cin >> args), ...);}
template<typename... T>
void put(T&&... args) { ((cout << args << " "), ...);}
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
#define putl(x) cout << x << endl;
#define debug(x) cout << #x << ": " << x << endl;
#define int long long

const ll inf = LLONG_MAX;
const ld ep = 0.0000001;
const ld pi = acos(-1.0);
const ll md = 1000000007;

int dis[501][501];

void solve(){
    int n,m,q; see(n,m,q);
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            dis[i][j] = (i==j) ? 0 : -1;
        }
    }
    for(int i = 0; i < m; i++){
        int s,t,w; see(s,t,w);
        dis[s][t] = dis[t][s] = (dis[s][t] == -1) ? w : min(dis[s][t], w);
    }
    for(int k = 1; k <= n; k++){
        for(int i = 1; i <= n; i++){
            for(int j = 1; j <= n; j++){
                if(dis[i][k] == -1 || dis[k][j] == -1)
                    continue;
                else if(dis[i][j] == -1)
                    dis[i][j] = dis[i][k] + dis[k][j];
                else
                    dis[i][j] = min(dis[i][j], dis[i][k] + dis[k][j]);
            }
        }
    }
    for(int i = 0; i < q; i++){
        int a,b; see(a,b);
        putl(dis[a][b]);   
    }
}

int32_t main(){
    ios::sync_with_stdio(0); cin.tie(0);
    solve();
}