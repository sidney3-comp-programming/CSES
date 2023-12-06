#include <bits/stdc++.h>
using namespace std;

template<typename... T>
void see(T&... args) { ((cin >> args), ...);}
template<typename... T>
void put(T&&... args) { ((cout << args << " "), ...);}
template<typename... T>
void putl(T&&... args) { ((cout << args << "\n"), ...);}
// #define ll long long
// #define ld long double
// #define ii pair<int, int>
// #define vi vector<int>
// #define vii vector<ii>
using ll = long long;
using ld = long double;
using ii = pair<int, int>;
using vi = vector<int>;
using vii = vector<pair<int, int>>;
#define rep(i,a,b) for(int i = a; i < b; i++)
#define pb push_back
#define mp make_pair
#define F first
#define S second
#define all(v) (v).begin(), (v).end()
#define sz size
#define debug(x) cout << #x << ": " << x << endl;

const ll inf = LLONG_MAX;
const ld ep = 0.0000001;
const ld pi = acos(-1.0);
const ll md = 1000000007;

constexpr int MAX_NODES = 100001;

int union_find(int x, vector<int>& set_union){
    if(x == set_union[x])
        return x;
    int x_parent = union_find(set_union[x], set_union);
    set_union[x] = x_parent;
    return x_parent;
}
void union_insert(int x, int y, vector<int>& set_union){
    int x_parent = union_find(x, set_union);
    int y_parent = union_find(y, set_union);
    if(x_parent == y_parent) return;
    set_union[x_parent] = y_parent;
}

void solve(){
    int n,m;
    cin >> n >> m;
    vii edges;
    for(int i =0;i<m;i++){
        int s,t; see(s,t);
        edges.pb(mp(s-1,t-1));
        edges.pb(mp(t-1,s-1));
    }
    vi set_union(n);
    for(int i = 0; i < n; i++)
        set_union[i] = i;
    for(ii edge : edges){
        union_insert(edge.F, edge.S, set_union);
    }
    vi delegates;
    set<int> represented;
    for(int i = 0; i < n; i++){
        int parent = union_find(i, set_union);
        if(represented.count(parent) == 0){
            represented.insert(parent);
            delegates.pb(i);
        }
    }
    putl(delegates.sz()-1);
    for(int i = 0; i < delegates.sz() - 1; i++){
        int s = delegates[i], t = delegates[i + 1];
        cout << s + 1 << " " << t + 1 << "\n";
    }

}

int32_t main(){
    ios::sync_with_stdio(0); cin.tie(0);
    solve();
}