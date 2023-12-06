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

class union_set{
    public:
    vi parent;
    vi c_size;
    int largest_component=1;
    union_set(int n): parent(n+1),c_size(n+1){
        for(int i=1;i<=n;i++){
            parent[i]=i;
            c_size[i]=1;
        }
    }
    int get_parent(int x){
        if(parent[x]==x)
            return x;
        parent[x]=get_parent(parent[x]);
        return parent[x];
    }
    bool join(int a, int b){
        int a_parent=get_parent(a), b_parent=get_parent(b);
        if(a_parent==b_parent)
            return false;
        if(c_size[a_parent]>c_size[b_parent]){
            c_size[a_parent]+=c_size[b_parent];
            parent[b_parent] =a_parent;
        }
        else{
            c_size[b_parent]+=c_size[a_parent];
            parent[a_parent] =b_parent;
        }
        largest_component=max({largest_component, c_size[a_parent], c_size[b_parent]});
        return true;
    }
    int get_largest_component(){
        return largest_component;
    }
};
void solve(){
    int n,m;
    see(n,m);
    vii edges;
    for(int i=0;i<m;i++){
        int s,t;
        see(s,t);
        edges.pb(mp(s,t));
    }
    int components = n;
    union_set u(n);
    for(auto [s,t] : edges){
        if(u.join(s,t))
            components--;
        cout<<components<< " " << u.get_largest_component() << "\n";
    }

}

int32_t main(){
    ios::sync_with_stdio(0); cin.tie(0);
    solve();
}