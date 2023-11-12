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

void solve(){
    string S;
    cin >> S;
    int N = S.size();
    vi  Z(N), vis(N);
    Z[0] = N;
    int L,R,k;
    L = R = 0;
    for(int i = 1; i < N; i++){
        if(i > R){
            L = R = i;
            while(R < N && S[R - L] == S[R]){
                R++;
            }
            Z[i] = R - L;
            R--;
        }
        else{
            k = i - L;
            if(Z[k] < R - i + 1) {
                Z[i] = Z[k];
            }
            else {
                L = i;
                while(R < N && S[R - L] == S[R]){
                    R++;
                }
                Z[i] = R - L;
                R--;
            }
        }
        vis[Z[i]] = 1;
    }
    for(int i = N - 1; i > 0; i--){
        int expected_size = N - i;
        if(Z[i] == expected_size){
            cout << expected_size << " ";
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