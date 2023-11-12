#include <bits/stdc++.h>
using namespace std;
#define REP(i,a,b) for(int i = a; i < b; i++)

int arr[200001];
int pfx[200001][31];

int main(){
    int n,q;
    cin >> n >> q;
    REP(i, 0, n){
        cin >> arr[i];
    }
    REP(bit, 0, 31){
        if((1<<bit) & arr[0]){
            pfx[0][bit] = 1;
        }
    }
    REP(i, 1, n){
        REP(bit, 0, 31){
            pfx[i][bit] = pfx[i-1][bit];
            if((1<<bit) & arr[i]){
                pfx[i][bit] += 1;
                pfx[i][bit] %= 2;
            }
        }
    }
    while(q--){
        int a,b;
        cin >> a >> b;
        a--;
        b--;
        int res = 0;
        REP(bit, 0, 31){
            int count = pfx[b][bit];
            if(a > 0){
                count -= pfx[a-1][bit];
            }
            if(count % 2 != 0){
                res += (1<<bit);
            }
        }
        cout << res << endl;
    }


}