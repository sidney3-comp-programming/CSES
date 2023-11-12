#include <bits/stdc++.h>
using namespace std;

#define REP(i,a,b) for(int i = a; i < b; i++)
typedef vector<int> vi;

int main(){
    int n,m;
    cin >> n >> m;
    vi hotels(n);
    vi groups(m);
    REP(i,0,n){
        cin >> hotels[i];
    }
    REP(i,0,m){
        cin >> groups[i];
    }
    int hotelPointer = 0;
    REP(groupPointer, 0, m){
        while(hotelPointer < n and hotels[hotelPointer] < groups[groupPointer]) hotelPointer++;
        if(hotelPointer == n){
            cout << 0 << " ";
        }
        else{
            cout << hotelPointer + 1 << " ";
            hotels[hotelPointer] -= groups[groupPointer];
        }
    }
    cout << endl;
}