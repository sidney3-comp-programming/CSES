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
    string s = "abaabab";
    vector<int> Z(s.size());
    Z[0] = s.size();
    int L = 0, R = 0;
    for(int i = 1; i < s.size(); i++){
        if(i > R){
            L = R = i;
            while(R < s.size() && s[R] == s[R - L]){
                R++;
            }
            Z[i] = R - L;
            R--;
        }
        else{
            int k = i - L; //S[i]... == S[k]...
            if(Z[k] < R - i + 1){
                Z[i] = Z[k];
            }
            else{
                L = i;
                while(R < s.size() && s[R] == s[R - L]){
                    R++;
                }
                Z[i] = R - L;
                R--;
            }

        }
    }
    for(int i : Z){
        cout << i << " ";
    }
}

int32_t main(){
    ios::sync_with_stdio(0); cin.tie(0);
    int t;
    cin >> t;
    while(t--){
        solve();
    }
}
