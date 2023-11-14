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
The minimum size should help us!

Want some kind of sliding window approach: fix the right side of our array. we won't be able to pull in deeper
than a, but we can pul out as deep as we want. Should we do so greedily?

How should we decide when to pull in the subarray?

1,1,-10,2,2. We want to figure out that we need to pull in the 1's... We can use prefix sum if we want
to get the sum. What's the subproblem? Brute force approach: for some end e,
just iterate through all the possible places that we could pull in. 

In general, if we are at index i, we will want to pull it in to the first negative subarray
Let dp[i] -> first index we have to jump to to be negative? idk seems hard. 
*/

void solve(){
}

int32_t main(){
    ios::sync_with_stdio(0); cin.tie(0);
    solve();
}