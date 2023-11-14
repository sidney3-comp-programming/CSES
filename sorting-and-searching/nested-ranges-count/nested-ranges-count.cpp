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
// #define int long long

const ll inf = LLONG_MAX;
const ld ep = 0.0000001;
const ld pi = acos(-1.0);
const ll md = 1000000007;

/*
We want to count, for each new value x, the number of values that we've seen before
x that exceed it. A natural way to do this would be to keep some kind of prefix sum...

Equivalent to saying how many values are less than current value

*/
const int FENWICK_SZ=400000;

class Fenwick{
    public:
    vi T;
    Fenwick(): T(FENWICK_SZ, 0){
    }
    void insert(int i){
        int idx=i+1;
        while(idx<FENWICK_SZ){
            T[idx-1]++;
            idx+=idx&-idx;
        }
    }
    int query(int i){
        int res=0,idx=i+1;
        while(idx > 0){
            res+=T[idx-1];
            idx-=idx&-idx;
        }
        return res;
    }
};

void solve(){
    int n; see(n);
    vec<vi> intervals(n);
    vi nums;
    rep(i,0,n){
        int a,b;
        see(a,b);
        nums.pb(a); nums.pb(b);
        intervals[i]={a,b,i};
    }
    sort(all(nums));
    auto last = unique(all(nums));
    vi unique_sorted(nums.begin(), last);
    unordered_map<int,int> enumeration;
    for(int i=0;i<unique_sorted.sz();i++)
        enumeration[unique_sorted[i]]=i;

    vi contains(n);
    sort(all(intervals), [](const vi& a, const vi& b){
        if(a[1] < b[1])
            return true;
        else if(b[1] < a[1])
            return false;
        else if(a[0] > b[0])
            return true;
        else
            return false;
    });
    Fenwick A;
    for(int i=0;i<n;i++){
        contains[intervals[i][2]]=i-A.query(enumeration[intervals[i][0]]-1);
        A.insert(enumeration[intervals[i][0]]);
    }

    sort(all(intervals), [](const vi& a, const vi& b){
        if(a[0] < b[0])
            return true;
        else if(b[0] < a[0])
            return false;
        else if(a[1] > b[1])
            return true;
        else
            return false;
    });
    vi contained(n);
    Fenwick B;
    for(int i=0;i<n;i++){
        contained[intervals[i][2]]=i-B.query(enumeration[intervals[i][1]]-1);
        B.insert(enumeration[intervals[i][1]]);
    }    
    for(int i=0;i<n;i++) cout << contains[i] << " ";
    cout << "\n";
    for(int i=0;i<n;i++) cout << contained[i] << " ";
}

int32_t main(){
    ios::sync_with_stdio(0); cin.tie(0);
    solve();
}