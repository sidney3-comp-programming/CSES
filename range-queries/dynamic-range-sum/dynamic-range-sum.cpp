#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> ii;
typedef vector<pair<int,int>> vii;

#define REP(i,a,b) for(int i = a; i < b; i++)
#define pb push_back
#define mp make_pair
#define F first
#define S second
#define all(v) (v).begin(), (v).end()
#define sz size
#define putl(x) cout << x << endl;
#define put(x) cout << x << " ";
#define debug(x) cout << #x << ": " << x << endl;
#define int long long int

int query(int i, const vector<int>& fenwick){
    int res = 0;
    while(i > 0){
        res += fenwick[i - 1];
        i -= i& (-i);
    }
    return res;
}

void update(int i, int x, vector<int>& fenwick){
    while(i <= fenwick.size()){
        fenwick[i- 1] += x;
        i += i& (-i);
    }
}
static constexpr int UPDATE = 1, QUERY = 2;
void solve(){
    int n,q;
    cin >> n >> q;
    vector<int> arr(n, -1), fenwick(n, 0);
    REP(i,0,n){
        cin >> arr[i];
        update(i + 1, arr[i], fenwick);
    }
    REP(i,0,q){
        int query_type;
        cin >> query_type;
        if(query_type == UPDATE){
            int idx, val;
            cin >> idx >> val;
            update(idx, val - arr[idx - 1], fenwick);
            arr[idx - 1] = val;
        }
        else if(query_type == QUERY) {
            int a,b;
            cin >> a >> b;
            cout << query(b, fenwick) - query(a - 1, fenwick) << endl;
        }
    }
}

int32_t main(){
    ios::sync_with_stdio(0); cin.tie(0);
    int t = 1;
    while(t--){
        solve();
    }
}