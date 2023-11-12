#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

#define REP(i,a,b) for(int i = a; i < b; i++)

vector<int> cubeHeights;


int main(){
    int numVals;
    int currVal;
    cin >> numVals;
    REP(i, 0, numVals){
        cin >> currVal;
        if(cubeHeights.size() == 0 || cubeHeights.back() <= currVal){
            cubeHeights.push_back(currVal);
        }
        else{
            auto greatestAfter = upper_bound(cubeHeights.begin(), cubeHeights.end(), currVal);
            *greatestAfter = currVal;
        }
    }
 
    cout << cubeHeights.size() << endl;

}