#include <algorithm>
#include <vector>
#include <deque>
#include <utility>
#include <iostream>

using namespace std;

#define REP(i,a,b) for(int i = a; i < b; i++)
#define pb push_back


int main(){
    long people, aparts, maxDiff;
    cin >> people >> aparts >> maxDiff;

    deque<pair<long,long>> desiredSizes;
    REP(i, 0, people){
        long desiredSize;
        cin >> desiredSize;
        desiredSizes.pb({desiredSize - maxDiff, desiredSize + maxDiff});
    }
    deque<long> apartSizes;
    REP(i, 0, aparts){
        long apartSize;
        cin >> apartSize;
        apartSizes.pb(apartSize);
    }
    sort(apartSizes.begin(), apartSizes.end());
    sort(desiredSizes.begin(), desiredSizes.end());

    int res = 0;
    while(desiredSizes.size() > 0 && apartSizes.size() > 0){
        pair<long, long> currPerson = desiredSizes.front();
        long currMinSize = apartSizes.front();
        //if the curr min apartment works for the smallest person, pair them up
        if(currPerson.first <= currMinSize && currPerson.second >= currMinSize){
            apartSizes.pop_front();
            desiredSizes.pop_front();
            res++;
        }
        //if the curr min apartment is too small for the smallest person, discard it
        else if(currPerson.first > currMinSize){
            apartSizes.pop_front();
        }
        //if the curr min person is too small for the smallest apartment, discard them
        else{
            desiredSizes.pop_front();
        }
    }
    cout << res;
}
// min applicant gets min apartment, repeat