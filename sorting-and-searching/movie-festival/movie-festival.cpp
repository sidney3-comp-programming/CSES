#include <algorithm>
#include <iostream>
#include <vector>
#include <iterator>

using namespace std;

#define REP(i, a,b) for(int i = a; i < b; i++)
#define pb push_back

vector<pair<long, long>> intervals;
int main(){
    int numMovies;
    cin >> numMovies;
    long startI,endI;
    REP(i, 0, numMovies){
        cin >> startI >> endI;
        intervals.pb({startI, endI});
    }
    sort(intervals.begin(), intervals.end());
    int currPtr = 0, nextPtr = 1, res = 1;
    while(nextPtr < intervals.size()){
        if(intervals[nextPtr].first >= intervals[currPtr].second){
            res++;
            currPtr = nextPtr;
            nextPtr = currPtr + 1;
        }
        else if(intervals[nextPtr].second < intervals[currPtr].second){
            currPtr = nextPtr;
            nextPtr = currPtr + 1;
        }
        else{
            nextPtr++;
        }
    }
    cout << res;
}