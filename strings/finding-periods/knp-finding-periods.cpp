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

const ll inf = LLONG_MAX;
const ld ep = 0.0000001;
const ld pi = acos(-1.0);
const ll md = 1000000007;


void solve(){
    string S;
    see(S);
    int n=S.sz();
    vi Z(n);
    int L=0,R=0;
    Z[0]=n;
    rep(i,1,n){
        if(R <= i){
            L=R=i;
            while(R<n && S[R]==S[R-L]){
                R++;
            }
            R--;
            Z[i]=R-L+1;
        }
        else{
            int k=i-L;
            if(Z[k] < R - i){
                Z[i]=Z[k];
            }
            else{
                L=i;
                while(R<n && S[R]==S[R-L]){
                    R++;
                }
                R--;
                Z[i]=R-L+1;
            }
        }
    }
    bool can_make;
    for(int s_len=1;s_len<=n;s_len++){
        can_make=true;
        for(int k=0; k<n && can_make; k += s_len){
            can_make=can_make && (Z[k]>=min(s_len,n-k));
        }
        if(can_make){
            printf("%d ",s_len);
        }
    }
}

int32_t main(){
    ios::sync_with_stdio(0); cin.tie(0);
    solve();
}