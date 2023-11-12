#include <iostream>
#include <cmath>

using namespace std;
#define REP(i, a, b) for(int i = a; i < b; i++)
#define INF 1e10

int main(){
    int numVals;
    cin >> numVals;
    long curr, currSum = 0, bestSum = -INF;
    REP(i, 0, numVals){
        cin >> curr;
        if(i == 0 || currSum > 0){
            currSum += curr;
        }
        else{
            currSum = curr;
        }
        bestSum = max(bestSum, currSum);
    }
    cout << bestSum << endl;
}