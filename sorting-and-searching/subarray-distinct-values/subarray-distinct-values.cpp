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
Calculate the number of subarrays that have at most k distinct values. This is equivalent to the number of total subarrays (n + 1)*n/2 minus the number
of subarrays with more than k distinct values

Idea 1: go through the integers in the subarray (distinct) and answer for each how many subarrays it is a member of. Seems not too unreasonable

Definitely going to be something with the frequency of the numbers and considering each number. NOT going to be some DP problem. 
So we look at some value x. We say that there are Z subarrays that contain the value x. I believe I can calculate this. But the trouble is, if we know this,
this doesn't quite get us to the answer.

Oh yea, let's iterate through the array. So say that we are at index i, and we want to say how many NEW subarrays we get that have at most k distinct values
(subarrays ending at index i). So we want to go as far back as we (greedily) can. Sliding window!


*/

void solve(){
    size_t n,k;
    cin >> n >> k;
    vi arr(n);
    for(size_t i = 0; i < n; i++){
        cin >> arr[i];
    }
    map<int, int> freq;
    int l = 0;
    long long res = 0;
    for(size_t r = 0; r < arr.size(); r++){
        freq[arr[r]]++;
        while(freq.size() > k){
            freq[arr[l]]--;
            if(freq[arr[l]] == 0){
                freq.erase(arr[l]);
            }
            l++;
        }
        res += r - l + 1;
    }
    cout << res << "\n";
}

int32_t main(){
    ios::sync_with_stdio(0); cin.tie(0);
    solve();
}