#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>

using namespace std;
#define REP(i,a,b) for(int i = a; i < b; i++)
#define pb push_back

vector<int> startTimes;
vector<int> exitTimes;

int main(){
    int customers;
    cin >> customers;
    long startTime, endTime;
    REP(i, 0, customers){
        cin >> startTime >> endTime;
        startTimes.pb(startTime);
        exitTimes.pb(endTime);
    }
    sort(startTimes.begin(), startTimes.end());
    sort(exitTimes.begin(), exitTimes.end());

    auto startIt = startTimes.begin(), exitIt = exitTimes.begin();
    int currCustomers = 0;
    while(startIt != startTimes.end()){
       //new customer enters the store: check if the prior customer has already left
       //if NOT, then count currCustomers as +1
       if(*startIt <= *exitIt){
        ++currCustomers;
       }
       else{
        //customers count remains unchanged
        ++exitIt;
       }
       ++startIt;
    }
    cout << currCustomers << endl;
}