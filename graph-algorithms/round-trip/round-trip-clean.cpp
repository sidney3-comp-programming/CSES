#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> ii;

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
#define loop(x) int asdf = x; while(asdf--)

vi   adj[100001];
vi   cyc        ;
bool vis[100001];

bool dfs(int curr, int prev){
    vis[curr] = true;
    for(int child : adj[curr]){
        cyc.pb(child);
        if(!vis[child]) {if(dfs(child, curr))return true;}
        else if(child != prev) return true;
        cyc.pop_back();
    }
    return false;
}

int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    int n,m;
    cin >> n >> m;
    loop(m){
        int s,t;
        cin >> s >> t;
        adj[s].pb(t);
        adj[t].pb(s);
    }
    REP(i,1,n+1){
        cyc.pb(i);
        if(!vis[i] and dfs(i, 0)){
            vi res = {*cyc.rbegin()};
            for(auto it = cyc.rbegin() + 1; it != cyc.rend(); it++){
                res.pb(*it);
                if(*it == *cyc.rbegin()) break;
            }
            putl(res.size());
            for(int k : res) put(k);
            return 0;
        }
        cyc.pop_back();
    }
    putl("IMPOSSIBLE");
}