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
static constexpr int MOD = (int) 1e9 + 7;
/*
dp(i) := number of word combinations for word[i:]
*/
int trie [1000005][26];
bool stop[1000005];
int dp   [5005];
int ct = 0;

void insert(const string& s){
    int node = 0;
    for(int i = 0; i < s.size(); i++){
        if(!trie[node][s[i] - 'a']){
            trie[node][s[i] - 'a'] = ++ct;
        }
        node = trie[node][s[i] - 'a'];
    }
    stop[node] = true;
}

int search(const int& x, const string& target){
    int res = 0, node = 0;
    for(int i = x; i < target.size(); i++){
        if(!trie[node][target[i] - 'a']){
            return res;
        }
        node = trie[node][target[i] - 'a'];
        if(stop[node]){
            res += dp[i + 1];
            res %= MOD;
        }
    }
    return res;
}
 
void solve(){
    string target;
    cin >> target;
    int n;
    cin >> n;
    REP(i,0,n){
        string s;
        cin >> s;
        insert(s);
    }
    dp[target.size()] = 1;
    for(int i = target.size() - 1; i >= 0; i--)
    {
        dp[i] = search(i, target);
    }
    cout << dp[0] << endl;
}

int32_t main(){
    ios::sync_with_stdio(0); cin.tie(0);
    solve();
}