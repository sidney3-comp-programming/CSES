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

/*
How many swaps will it take? We can just simulate? Iterate through the nu
If we swap two numbers, will this require an extra pass / will this save us a pass?

In general, for each number, whether or not it requires a pass depends on if the value that precedes it
comes before it in the list, except for 1, which always requires a pass.

4 1 2 5 3

Say we swap 4,3. Beforehand, 4 did not require a pass and 3 did not require a pass.
Afterwards, 4 will still not require a pass, and 3 will now require a pass
*/
int brute_force(vi &arr){
    vi idx(arr.size() + 1);
    for(size_t i = 0; i < arr.size(); i++){
        idx[arr[i]] = i;
    }
    int res = 1;

    for(size_t i = 2; i < arr.size() + 1; i++){
        if(idx[i] < idx[i-1]){
            res++;
        }
    }
    return res;
}

void solve(){
    int n, m;
    cin >> n >> m;
    vi arr(n), idx(n + 1);
    for(int i = 0; i < n; i++){
        cin >> arr[i];
        idx[arr[i]] = i;
    }
    int passes = brute_force(arr);
    // 4 1 2 5 3
    // 4 already took a pass, 3 did not take a pass
    // 3 1 2 5 4
    for(int i = 0; i < m; i++){
        int i1,i2;
        cin >> i1 >> i2;
        i1--;
        i2--;
        int a = arr[i1], b = arr[i2];
        int pass_delta = 0;
        if(a == 1 || idx[a] < idx[a - 1]) pass_delta--;
        if(b == 1 || idx[b] < idx[b - 1]) pass_delta--;
        if(a != n && idx[a + 1] < idx[a] && a + 1 != b) pass_delta--;
        if(b != n && idx[b + 1] < idx[b] && b + 1 != a) pass_delta--;

        arr[i1] = b;
        arr[i2] = a;
        idx[a]  = i2;
        idx[b]  = i1;

        if(a == 1 || idx[a] < idx[a - 1]) pass_delta++;
        if(b == 1 || idx[b] < idx[b - 1]) pass_delta++;
        if(a != n && idx[a + 1] < idx[a] && a + 1 != b) pass_delta++;
        if(b != n && idx[b + 1] < idx[b] && b + 1 != a) pass_delta++;


        passes += pass_delta;
        cout << passes << "\n";
    }

}

int32_t main(){
    ios::sync_with_stdio(0); cin.tie(0);
    solve();
}
