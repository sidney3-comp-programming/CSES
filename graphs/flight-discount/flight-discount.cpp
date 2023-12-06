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

bool   used_vis[100001];
int    used_dis[100001];
bool unused_vis[100001];
int  unused_dis[100001];

vii         adj[100001];

struct cmp{
    bool operator()(vi a, vi b){
        return a[0] > b[0];
    }
};

void solve(){
    int n,m;
    cin >> n >> m;
    for(int i=0;i<m;i++){
        int s,t,c;
        see(s,t,c);
        adj[s].pb(mp(t,c));
    }
    priority_queue<vi, vector<vi>, cmp> pq;
    pq.push({0,1,0});
    unused_dis[1] = 0;
    fill(begin(unused_dis), end(unused_dis), inf);
    fill(begin(used_dis), end(used_dis), inf);
    fill(begin(used_vis), end(used_vis), false);
    fill(begin(unused_vis), end(unused_vis), false);

    while(!pq.empty()){
        vi tp = pq.top();
        int curr_cost = tp[0], curr = tp[1], ticket_used = tp[2];
        pq.pop();
        if(ticket_used){
            if(used_vis[curr])
                continue;
            used_vis[curr] = true;
            for(auto [next, edge_weight] : adj[curr]){
                if(!used_vis[next] && used_dis[next] > edge_weight + curr_cost){
                    used_dis[next] = edge_weight + curr_cost;
                    pq.push({used_dis[next], next, 1});
                }
            }
        }
        else{
            if(unused_vis[curr])
                continue;
            unused_vis[curr] = true;
            for(auto [next, edge_weight] : adj[curr]){
                if(!used_vis[next] && used_dis[next] > edge_weight/2 + curr_cost){
                    used_dis[next] = edge_weight/2 + curr_cost;
                    pq.push({used_dis[next], next, 1});
                }
                if(!unused_vis[next] && unused_dis[next] > edge_weight + curr_cost){
                    unused_dis[next] = edge_weight + curr_cost;
                    pq.push({unused_dis[next], next, 0});
                }
            }
        }
    }
    cout << used_dis[n] << "\n";

}

int32_t main(){
    ios::sync_with_stdio(0); cin.tie(0);
    solve();
}