#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<int> vi;

#define REP(i,a,b) for(int i = a; i < b; i++)
#define pb push_back
#define mp make_pair
#define f first
#define s second
#define all(v) (v).begin(), (v).end()
#define sz(v) (int)(v).size()
#define debug(x) cout << #x << ": " << x << endl;

int INF = (int)1e9 + 7;

bool cmp(vi a, vi b){
    if(a[0] < b[0]){
        return true;
    }
    else if(a[0] > b[0]){
        return false;
    }
    else if(a[1] > b[1]){
        return true;
    }
    else{
        return false;
    }
}

int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    int n, a,b;
    vector<vi> pairs; //start is 0, end is 1, index is 2
    cin >> n;
    REP(i, 0, n){
        cin >> a >> b;
        pairs.pb({a,b,i});
    }

    sort(pairs.begin(), pairs.end(), cmp);

    vi contains(n);
    vi contained(n);
    
    int mx = -1;

    for(auto it = pairs.begin(); it != pairs.end(); it++){
        if((*it)[1] <= mx){
            contained[(*it)[2]] = 1;
        }
        mx = max(mx, (*it)[1]);
    }
    int mn = INF;
    for(auto it = pairs.rbegin(); it != pairs.rend(); it++){
        if((*it)[1] >= mn){
            contains[(*it)[2]] = 1;
        }
        mn = min(mn, (*it)[1]);
    }
    for(int p : contains){
        cout << p << " ";
    }
    cout << endl;
    for(int k : contained){
        cout << k << " ";
    }
}