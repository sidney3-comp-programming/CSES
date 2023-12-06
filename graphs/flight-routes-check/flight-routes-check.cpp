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

const int UNVISITED=0,VISITING=1,VISITED_GOOD=2,VISITED_BAD=3;

bool dfs(vec<int>& state, const vec<vi>& adj, int curr)
{
    if(curr==1)
    {
        return true;
    }
    if(state[curr] != UNVISITED){
        return state[curr] == VISITED_GOOD;
    }
    bool res=false;
    for(int next : adj[curr])
    {
        if(state[next]==UNVISITED)
        {
            res=res||dfs(state,adj,next);
        }
        else if(state[next]!=VISITING)
        {
            res=res||(state[next]==VISITED_GOOD);
        }
    }
    state[curr]=res?VISITED_GOOD : VISITED_BAD;
    return res;

}

bool maps_from(vec<vi>& adj, ii& bad_pair, const int n)
{
    vec<int> state(n + 1, UNVISITED);
   
    for(int i=1;i<=n;i++)
    {
        if(!dfs(state,adj,i))
        {
            bad_pair.F=i;
            bad_pair.S=1;
            return false;
        }
    }
    return true;
}
bool maps_to(vec<vi>& adj, ii& bad_pair, const int n){
    queue<int> q;
    q.push(1);
    vec<bool> vis(n + 1, false);
    vis[1]=true;
    while(!q.empty()){
        int curr=q.front();
        q.pop();
        for(int next : adj[curr])    
        {
            if(!vis[next])
            {
                vis[next]=true;
                q.push(next);
            }
        }
    }
    for(int i=1;i<=n;i++)   
    {
        if(!vis[i])
        {
            bad_pair.F=1;
            bad_pair.S=i;
            return false;
        }
    }
    return true;
}

void solve(){
    int n,m;
    see(n,m);
    vec<vi> adj(n);
    rep(i,0,n){
        int s,t;
        see(s,t);
        adj[s].pb(t);
    }
    ii bad_pair;
    if(!maps_to(adj,bad_pair,n) || !maps_from(adj, bad_pair,n))
    {
        cout<<"NO\n"<<bad_pair.F<<" "<<bad_pair.S<<"\n";
    }
    else
    {
        cout<<"YES\n";
    }

}

int32_t main(){
    ios::sync_with_stdio(0); cin.tie(0);
    solve();
}
