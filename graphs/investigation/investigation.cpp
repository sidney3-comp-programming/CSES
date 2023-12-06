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

vii        adj[100001];
vii pruned_adj[100001];
int        dis[100001];

vi pruned_mapsto[100001];

bool ready[100001];
int     dp[100001];
int num_paths(int curr){
    if(curr == 1)
        return 1;
    if(ready[curr])
        return dp[curr];
    int res = 0;
    for(int prev : pruned_mapsto[curr]){
        res += num_paths(prev);
        res %= md;
    }
    ready[curr]=true;
    dp   [curr]=res;
    return res;
}

int shortest_path(int start, int end, int num_nodes){
    vector<bool> vis(num_nodes + 1, false);
    vis[1] = true;
    queue<ii> q;
    q.push(mp(start, 0));
    while(!q.empty()){
        auto [curr, curr_dis] = q.front();
        q.pop();
        if(curr == end)
            return curr_dis;
        for(auto [next, _] : pruned_adj[curr]){
            if(vis[next])
                continue;
            vis[next] = true;
            q.push(mp(next, curr_dis+1));
        }
    }
    return -1;
}

int longest_path(int start, int end, int num_nodes){
    vi capacity     (num_nodes + 1, 0);
    vector<bool> vis(num_nodes + 1, false);
    //prune capacity
    queue<int> q;
    q.push(start);
    while(!q.empty()){
        int curr = q.front();
        q.pop();
        for(auto [next, _] : pruned_adj[curr]){
            capacity[next]++;
            if(!vis[next])
                q.push(next);
            vis[next] = true;
        }
    }
    fill(all(vis), false);
    vector<int> saturation(num_nodes + 1, 0);
    queue<pair<int,int>> qq;
    qq.push(mp(1,0));
    while(!qq.empty()){
        auto [curr, curr_dis] = qq.front();
        qq.pop();
        if(curr == end)
            return curr_dis;
        for(auto [next, _] : pruned_adj[curr]){
            if(vis[next])
                continue;
            saturation[next]++;
            if(saturation[next] == capacity[next]){
                vis[next]=true;
                qq.push(mp(next,curr_dis+1));
            }
        }
    }
    return -1;
}

void solve(){
    int n,m;
    see(n,m);
    for(int i=0;i<m;i++){
        int s,t,c;
        see(s,t,c);
        adj[s].pb(mp(t,c));
    }
    fill(begin(dis), end(dis), inf);
    dis[1] = 0;
    vector<bool> vis(n + 1, false);
    priority_queue<ii, vii, greater<ii>> pq;
    pq.push(mp(0,1));
    while(!pq.empty()){
        auto [curr_cost, curr] = pq.top();
        pq.pop();
        if(vis[curr])
            continue;
        vis[curr] = true;
        for(auto [next, edge_weight] : adj[curr]){
            if(curr_cost + edge_weight <= dis[next]){
                pruned_adj[curr].pb(mp(next, edge_weight));
                pruned_mapsto[next].pb(curr);
                if(curr_cost + edge_weight < dis[next]){
                    pq.push(mp(curr_cost + edge_weight, next));
                    dis[next] = curr_cost + edge_weight;
                }
            }
        }
    }

    if(dis[n] == inf){
        putl("IMPOSSIBLE");
        return;
    }
    put(dis[n]);
    put(num_paths(n));
    put(shortest_path(1,n,n));
    put(longest_path(1,n,n));

}

int32_t main(){
    ios::sync_with_stdio(0); cin.tie(0);
    solve();
}