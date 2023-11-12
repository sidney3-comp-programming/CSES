#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

#define REP(i,a,b) for(int i = a; i < b; i++)

int main(){
    int n;
    cin >> n;
    vector<int> seen;
    while(cin >> n){
        seen.push_back(n);
    }
    sort(seen.begin(), seen.end());
    int res = 0;
    REP(i, 0, seen.size()){
        if(i == 0 || seen[i] != seen[i-1]){
            res++;
        }
    }
    cout << res;
}