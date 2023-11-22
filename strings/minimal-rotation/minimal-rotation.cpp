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
We want to make some sort of trie structure: have a node A that maps to several other letters...
The problem with having one node for every letter -> hard to avoid self loops...

LOVE the idea of having a node for each letter. Makes it so easy to compute the best path. Start
at the best letter -> take the best path.
MAYBE we can make some constant time way of checking if a given string is a subset of a rotation of the main string?
hashing approach... Can we come up with that? Oh actually -> we should just compute the hash codes and take
the minimum of them. Very natural way to do it. With Robin Karp! Mehhhh. Can't really compare - not meant for that

*/
void solve(){
}

int32_t main(){
    ios::sync_with_stdio(0); cin.tie(0);
    int t;
    see(t);
    while(t--)
        solve();
}