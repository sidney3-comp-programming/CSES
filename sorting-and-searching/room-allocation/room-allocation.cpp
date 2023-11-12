#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <unordered_map>

using namespace std;
#define REP(i,a,b) for(int i = a; i < b; i++)
#define pb push_back
#define mp make_pair
typedef pair<int, int> ii; 
typedef vector<int> vi;
typedef vector<pair<int,int>> vii;



int main(){
    int n, start, end;
    vii starts; // (start, index)
    vii ends; // (end, index)
    unordered_map<int, int> assignments;
    cin >> n;

    REP(i,0,n){
        cin >> start >> end;
        starts.pb(mp(start, i));
        ends.pb(mp(end, i));
    }
    sort(starts.begin(), starts.end());
    sort(ends.begin(), ends.end());

    int currEnd = 0, currRoom = 1;
    REP(currStart, 0, n){
        if(starts[currStart].first <= ends[currEnd].first){ //need to pop new room
            int room = currRoom;
            assignments[starts[currStart].second] = room;
            currRoom++;
        }
        else{
            int oldRoom = assignments[ends[currEnd].second];
            assignments[starts[currStart].second] = oldRoom;
            currEnd++;
        }
    }
    cout << currRoom - 1 << endl;
    REP(i, 0, n){
        cout << assignments[i] << " ";
    }
    cout << endl;
}
