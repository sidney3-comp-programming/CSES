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
#define INF = (int) 1e9

vi   adj[200001];
bool vis[200001];
vi   long_path;
vi   stck;

void dfs(int curr, int prev, int target){
    stck.pb(curr);
    if(curr == target){
        long_path.assign(stck.begin(), stck.end());
    }
    else{
        for(int next : adj[curr]){
            if(next == prev) continue;
            dfs(next, curr, target);
        }
    }
    stck.pop_back();
}

int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    int n;
    cin >> n;
    REP(i,0,n-1){
        int a,b;
        cin >> a >> b;
        adj[a].pb(b);
        adj[b].pb(a);
    }
    vi q = {1};
    vis[1] = true;
    int special1 = -1;
    while(q.size() > 0){
        vi nextq;
        for(int node : q){
            for(int next : adj[node]){
                if(vis[next]) continue;
                vis[next] = true;
                nextq.pb(next);
            }
        }
        if(nextq.size() == 0){
            special1 = q[0];
        }
        q = nextq;
    }
    int special2;
    q = {special1};
    fill(vis, vis + n + 1, false);
    vis[special1] = true;
    while(q.size() > 0){
        vi nextq;
        for(int node : q){
            for(int next : adj[node]){
                if(vis[next]) continue;
                vis[next] = true;
                nextq.pb(next);
            }
        }
        if(nextq.size() == 0){
            special2 = q[0];
        }
        q = nextq;
    }
    dfs(special1, 0, special2);
    cout << long_path[floor(long_path.size() / 2)] << endl;

}