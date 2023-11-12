#include <bits/stdc++.h>
using namespace std;

#define REP(i,a,b) for(int i = a; i < b; i++)

int main(){
    int n, q;
    cin >> n >> q;
    int mat[n][n];
    int pfxmat[n][n];
    char c;
    REP(i,0,n){
        REP(j,0,n){
            cin >> c;
            mat[i][j] = (c == '*') ? 1 : 0;
        }
    }
    pfxmat[0][0] = mat[0][0];
    REP(i,1,n){
        pfxmat[0][i] = pfxmat[0][i-1] + mat[0][i];
    }

    REP(i,1,n){
        pfxmat[i][0] = pfxmat[i-1][0] + mat[i][0];
    }
    REP(i,1,n){
        REP(j,1,n){
            pfxmat[i][j] = mat[i][j] + pfxmat[i-1][j] + pfxmat[i][j-1] - pfxmat[i-1][j-1];
        }
    }

    int y1,x1,y2,x2;
    while(q--){
        cin >> x1 >> y1 >> x2 >> y2;
        int res = pfxmat[x2-1][y2-1];
        if(y1 > 1){
            res -= pfxmat[x2-1][y1-2];
        }
        if(x1 > 1){
            res -= pfxmat[x1-2][y2-1];
        }
        if(x1 > 1 and y1 > 1){
            res += pfxmat[x1-2][y1-2];
        }
        cout << res << endl;
    }

}