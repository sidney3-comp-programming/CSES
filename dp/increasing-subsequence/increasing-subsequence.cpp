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

const int ARR_SZ = 200001;
class fenwick{
    public:
    vi T;
    fenwick(): T(ARR_SZ,0){}
    void insert(int i, int x){
        int idx=i+1;
        while(idx <= ARR_SZ){
            T[idx-1] = max(T[idx-1],x);
            idx+=idx&-idx;
        }
    }
    int query(int i){
        int idx=i+1,res=0;
        while(idx>0){
            res=max(res,T[idx-1]);
            idx-=idx&-idx;
        }
        return res;
    }
};

void solve(){
    int n;
    see(n);
    vii arr(n);
    rep(i,0,n){
        int x; see(x);
        arr[i]=mp(i,x);
    }
    sort(all(arr), [](const ii& a, const ii&b){
        if(a.S < b.S)
            return true;
        else if(a.S > b.S)
            return false;
        else if(a.F > b.F)
            return true;
        else
            return false;
    });
    fenwick f;
    int res=1;
    for(auto [i,x] : arr){
        int best_till=f.query(i);
        f.insert(i,best_till+1);
        res=max(res,best_till+1);
    }
    putl(res);
}

int32_t main(){
    ios::sync_with_stdio(0); cin.tie(0);
    solve();
}