#include <iostream>
#include <cmath>

using namespace std;

int main(){
    long n;
    long res = 0, curr = 5;
    cin >> n;

    while(curr <= n){
        res += floor(n / curr);
        curr *= 5;
    }
    cout << res << "\n";
}