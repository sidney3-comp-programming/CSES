#include <iostream>

using namespace std;

#define REP(i,a,b) for(int i = a; i < b; i++)

bool solve(long a, long b){
    if((a - 2*b) % 3 != 0) return false;
    long x = -(a-2*b)/3;
    long y = b - 2*x;
    return (x >= 0 && y >= 0);
}

int main(){
    int n;
    cin >> n;
    REP(i, 0, n){
        long a,b;
        cin >> a >> b;
        if(solve(a,b)) cout << "YES\n";
        else cout << "NO\n";
    }
}