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

priority_queue<int, vi, less<int>> cheapest_route[100001];

vii  adj[100001];
int vis[100001];

void solve(){
    int n,m,k;
    see(n,m,k);
    for(int i=0;i<m;i++){
        int s,t,c;
        see(s,t,c);
        adj[s].pb(mp(c,t));
    }
    fill(begin(vis), end(vis), 0);
    priority_queue<ii, vii, greater<ii>> pq;
    pq.push(mp(0, 1));
    while(!pq.empty()){
        auto [curr_cost, curr] = pq.top();
        pq.pop();
        if(vis[curr] >= k)
            continue;
        vis[curr]++;
        for(auto [edge_cost, next] : adj[curr]){
            if(cheapest_route[next].size() < k){
                cheapest_route[next].push(curr_cost + edge_cost);
                pq.push(mp(curr_cost + edge_cost, next));
            }
            else if(cheapest_route[next].top() > curr_cost + edge_cost){
                cheapest_route[next].pop();
                cheapest_route[next].push(curr_cost + edge_cost);
                pq.push(mp(curr_cost + edge_cost, next));
            }
        }
    }
    vi res;
    while(!cheapest_route[n].empty()){
        res.pb(cheapest_route[n].top());
        cheapest_route[n].pop();
    }
    for(auto it = res.rbegin(); it != res.rend(); it++){
        cout << *it << " ";
    }
    cout << endl;

}

int32_t main(){
    ios::sync_with_stdio(0); cin.tie(0);
    solve();
}