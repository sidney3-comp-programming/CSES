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

bool can_partition(int x, int k, const vi& arr){
    int partitions_needed=0,curr_component=0;
    for(int y : arr){
        if(curr_component + y > x){
            partitions_needed++;
            curr_component=0;
        }
        curr_component+=y;
    }
    return partitions_needed+1<=k && curr_component<=x;
}
void solve(){
    int n,k; see(n,k);
    vi arr(n);
    ll accum =0;
    for(int i=0;i<n;i++){
        cin>>arr[i];
        accum+=arr[i];
    }
    int l=*max_element(all(arr)),r=accum;
    int res=r;
    while(l<=r){
        int m=(l+r)/2;
        if(can_partition(m,k,arr)){
            res=m;
            r=m-1;
        }
        else{
            l=m+1;
        }
    }
    cout<<res<<"\n";
}

int32_t main(){
    ios::sync_with_stdio(0); cin.tie(0);
    solve();
}