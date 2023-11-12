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

ll pfx[200001];   

int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    int n, q;
    cin >> n >> q;
    fill(pfx, pfx + n + 1, 0);
    cin >> pfx[0];
    REP(i,1,n){
        cin >> pfx[i];
        pfx[i] += pfx[i - 1];
    }
    REP(query, 0, q){
        int a,b;
        cin >> a >> b;
        a--;
        b--;
        ll res = pfx[b];
        if(a > 0){
            res -= pfx[a - 1];
        }
        putl(res);
    }
}