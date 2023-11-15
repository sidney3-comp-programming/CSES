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
 
int dfs(int curr, vi& dis_to_cycle, vi& next){
    if(dis_to_cycle[curr]!=-1)
        return dis_to_cycle[curr];
    dis_to_cycle[curr]=1+dfs(next[curr], dis_to_cycle, next);
    return dis_to_cycle[curr];
}
const int UNVISITED=0,TREE=1,CYCLE=2,PLACEHOLDER=3;
void solve(){
    int n,q;
    see(n,q);
    vi next(n+1);
    for(int i=1;i<=n;i++)
        cin>>next[i];
 
    map<int,int> cycle_index;
    vec<map<int,int>> cycles;
    vi label(n+1, UNVISITED);
    vi dis_to_cycle(n+1, -1);
 
    for(int p=1;p<=n;p++){
        if(label[p]!=UNVISITED)
            continue;
        vi path;
        int curr=p;
        while(label[curr]==UNVISITED){
            label[curr]=PLACEHOLDER;
            path.pb(curr);
            curr=next[curr];
        }
        if(label[curr] != PLACEHOLDER){
            for(int x : path){
                cycle_index[x] = cycle_index[curr];
                label[x] = TREE;
            }
            continue;
        }
        auto cycle_pos=find(all(path),curr);
        map<int,int> cycle_data;
 
        for(auto it=path.begin();it!=cycle_pos;it++){
            cycle_index[*it]=cycles.sz();
            label      [*it]=TREE;
        }
        int cycle_idx=0;
        while(cycle_pos != path.end()){
            label       [*cycle_pos]=CYCLE;
            cycle_index [*cycle_pos]=cycles.sz();
            cycle_data  [*cycle_pos]=cycle_idx;
            dis_to_cycle[*cycle_pos]=0;
 
            cycle_idx++;
            cycle_pos++; 
        }
        cycles.pb(cycle_data);
    }
    for(int i=1;i<=n;i++)
        dfs(i,dis_to_cycle,next);
    
    vec<vi> succ(n+1, vi(25,-1));
    for(int i=1;i<=n;i++)
        succ[i][0]=next[i];
    for(int j=1;j<25;j++)
        for(int p=1;p<=n;p++)
            succ[p][j] = succ[succ[p][j-1]][j-1];
    
    auto jump = [](int start, int steps, vec<vi>& succ){
        int curr=start;
        for(int i=0;i<25;i++){
            if((1<<i)&steps)
                curr=succ[curr][i];
        }
        return curr;
    };
    vi res(q);
    for(int i=0;i<q;i++){
        int start,target;
        see(start,target);
        if(start==target){
            res[i]=0;
            continue;
        }
        if(label[start]==CYCLE && label[target]==CYCLE){
            if(cycle_index[start]==cycle_index[target]){
                map<int,int> *shared_cycle=&cycles[cycle_index[start]];
                int start_idx=(*shared_cycle)[start],target_idx=(*shared_cycle)[target];
                res[i]=(target_idx-start_idx+(*shared_cycle).sz()) % (*shared_cycle).sz();
            }
            else{
                res[i]=-1;
            }
        }
        else if(label[start]==TREE && label[target] == TREE){
            int start_dis=dis_to_cycle[start], target_dis=dis_to_cycle[target];
            if(start_dis < target_dis){
                res[i] = -1;
            }
            else{
                int jmp_size = start_dis-target_dis;
                if(jump(start, jmp_size,succ) == target)
                    res[i]=jmp_size;
                else
                    res[i]=-1;
            }
        }
        else if(label[start]==CYCLE && label[target]==TREE){
            res[i]=-1;
        }
        else if(label[start]==TREE && label[target]==CYCLE){
            if(cycle_index[start]==cycle_index[target]){
                map<int,int> *shared_cycle=&cycles[cycle_index[start]];
                int cycle_entry=jump(start, dis_to_cycle[start],succ);
                int entry_index= (*shared_cycle)[cycle_entry];
                int target_index=(*shared_cycle)[target];
                int cycle_dis   =(target_index-entry_index+(*shared_cycle).sz())%(*shared_cycle).sz();
                res[i] = cycle_dis + dis_to_cycle[start];
            }
            else{
                res[i]=-1;
            }
        }
        else{
            cerr<<"Nodes not labeled!\n";
            debug(label[start]);
            debug(label[target]);
        }
    }
    for(int x : res)
        putl(x);
}
 
int32_t main(){
    ios::sync_with_stdio(0); cin.tie(0);
    solve();
}