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

/*
reduces to MST
*/
class union_set{
    public:
    union_set(int n): comp_sz(n+1), parent(n+1) {
        for(int i=1;i<=n;i++){
            comp_sz[i]=1;
            parent [i]=i;
        }
    }
    bool join(int a, int b){
        int a_parent=get_parent(a),b_parent=get_parent(b);
        if(a_parent==b_parent)
            return false;
        if(comp_sz[a_parent]>comp_sz[b_parent]){
            parent[b_parent]=a_parent;
            comp_sz[a_parent]+=comp_sz[b_parent];
        }
        else{
            parent[a_parent]=b_parent;
            comp_sz[b_parent]+=comp_sz[a_parent];
        }
        return true;
    }
    private:
    vi comp_sz;
    vi parent;
    int get_parent(int x){
        if(parent[x] == x)
            return x;
        int res=get_parent(parent[x]);
        parent[x]=res;
        return res;
    }
};


void solve(){
    int n,m;
    see(n,m);
    vec<vi> edges;
    for(int i=0;i<m;i++){
        int s,t,w;
        see(s,t,w);
        edges.pb({s,t,w});
    }
    sort(all(edges), [](const vi& a, const vi& b){
        return a[2]<b[2];
    });
    int res=0;
    int num_components=n;
    union_set u(n);
    for(vi edge : edges){
        int s=edge[0],t=edge[1],w=edge[2];
        if(u.join(s,t)){
            num_components--;
            res+=w;
        }
        if(num_components == 1)
            break;
    }
    if(num_components==1){
        putl(res);
    }
    else{
        putl("IMPOSSIBLE");
    }
}

int32_t main(){
    ios::sync_with_stdio(0); cin.tie(0);
    solve();
}