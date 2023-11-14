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
Bold hypothesis: have each traverse the list of books in opposite order (one is reading the most expensive books first, one the 
least expensive books first).

Say that we don't do this - say that we use a more complicated strategy where the other person will skip over the book...
What changes?

*/
void solve(){
    int n;
    see(n);
    vii books1(n);
    for(int i=0;i<n;i++)
        int x; see(x);
        books[i]=mp(i,x);
    vii books2(books1);
    sort(all(books1), [](const ii&a, const ii&b){return a.S < b.S});
    sort(all(books2), [](const ii&a, const ii&b){return a.S > b.S});
    int b1_rem = books1.back(), b2_rem=books2.back();
    ll res = 0;
    while(!books1.empty() && !books2.empty()){
        if(books1.back().F != books2.back().F){

        }
        else{
            
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