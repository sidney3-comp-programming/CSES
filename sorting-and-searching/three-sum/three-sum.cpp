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

void solve(){
    int n,x;
    see(n,x);
    if(n<3){
        cout<<"IMPOSSIBLE\n";
        return;
    }
    vii arr(n);
    for(int i=0;i<n;i++){
        int y;
        see(y);
        arr[i]=mp(i,y);
    }
    sort(all(arr), [](const ii& a, const ii& b){return a.S < b.S;});
    for(int M=0;M<arr.size()-2;M++){
        int t=x-arr[M].S;
        int l=M+1,r=arr.size()-1;

        while(l<r){
            int y=arr[l].S+arr[r].S;
            if(y < t){
                l++;
            }
            else if(y > t){
                r--;
            }
            else{
                cout << arr[M].F + 1 << " " << arr[l].F + 1 << " " << arr[r].F + 1 << "\n";
                return;
            }
        }
    }
    cout << "IMPOSSIBLE\n";
    return;
}

int32_t main(){
    ios::sync_with_stdio(0); cin.tie(0);
    solve();
}