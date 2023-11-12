#include <iostream>

using namespace std;

#define REP(i,a,b) for(int i = a; i < b; i++)

long MODULO = 1e9 + 7;

int main(){
    int n;
    cin >> n;
    long res = 1;
    REP(i, 0, n){ 
        res = (res * 2) % MODULO;
    }
    cout << res << "\n";
}