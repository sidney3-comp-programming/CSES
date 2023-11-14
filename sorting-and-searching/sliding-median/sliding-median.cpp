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
We say in general that the smaller set will be the slightly
larger one
*/
class MedianStream{
    public:
    int query(){
        return *(small.rbegin());
    }
    void remove(int x){
        if(small.find(x) != small.end()){
            small.erase(small.find(x));
        }
        else if(big.find(x) != small.end()){
            big.erase(big.find(x));
        }
        rebalance();
    }
    void insert(int x){
        if(small.sz()==0){
            small.insert(x);
            return;
        }
        if(x >= *(small.rbegin())){
            big.insert(x);
        }
        else{
            small.insert(x);
        }
        rebalance();
    }
    private:
    multiset<int> big;
    multiset<int> small;
    void rebalance(){
        if(big.sz()>small.sz()){
            int shifted=*(big.begin());
            big.erase(big.find(shifted));
            small.insert(shifted);
        }
        else if(small.sz()-1>big.sz()){
            int shifted=*(small.rbegin());
            small.erase(small.find(shifted));
            big.insert(shifted);
        }
    }
};

void solve(){
    int n,k; see(n,k);
    MedianStream medianWindow;
    vi arr(n);
    for(int i=0;i<n;i++)
        cin >> arr[i];
    
    for(int i=0;i<k;i++)
        medianWindow.insert(arr[i]);

    vi res = {medianWindow.query()};
    for(int j=k;j<n;j++){
        medianWindow.insert(arr[j]);
        medianWindow.remove(arr[j-k]);
        res.pb(medianWindow.query());
    }
    for(int x : res) cout << x << " ";
    cout << "\n";
}

int32_t main(){
    ios::sync_with_stdio(0); cin.tie(0);
    solve();
}