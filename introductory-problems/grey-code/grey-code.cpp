/*
Again, seems like the conditions are not particularly stringent, and this is more about
defining some pattern that will work.

How many bits will there be with 0, n bytes? Exactly 1. How many bits with exactly one 1? exactly n
How many with exactly 2?(n choose 2). How many with exactly 3? (n choose 3).
This suggests a potential strategy:
0,1,2,1,2,..., do all the 1s, 3,2,3,2,3,2,..., do all the threes.

The key thing to note is that the distribution of the numbers of bits is symmetric:
i.e. for 6, it will peak out at 3, and the following will be true

0 = 6
1 = 5
2 = 4
3 = big

And then for 7, it will look like the following:
0 = 7
1 = 6
2 = 5
3 = 4

How many new possibilites do we get with the addition of each new bit?


*/

#include <iostream>
#include <vector>
#include <unordered_map>
#include <string>
#include <utility>
#include <algorithm>

#define pb push_back
#define REP(i,a,b) for (int i = a; i < b; i++)

using namespace std;

unordered_map<int, vector<string>> weightToBits;

int n;

pair<string, int> bitToString(int bitVal){
    pair<string, int> res = {"", 0};
    REP(i, 0, n){
        int currBit = 1 << i;
        if((bitVal & currBit) != 0){
            res.first += "1";
            res.second++;
        }
        else{
            res.first += "0";
        }
    }
    reverse(res.first.begin(), res.first.end());

    return res;
}

int main(){
    cin >> n;
    REP(i, 0, (1 << n)){
        pair<string, int> val = bitToString(i);
        weightToBits[val.second].pb(val.first);
    }

    int currWeight = 0;
    while(currWeight <= n){
        while(weightToBits[currWeight].size() > 0){
            cout << weightToBits[currWeight].back() << endl;
            weightToBits[currWeight].pop_back();
            if(weightToBits[currWeight+1].size() > 0 && weightToBits[currWeight].size() > 0){
                cout << weightToBits[currWeight + 1].back() << endl;
                weightToBits[currWeight + 1].pop_back();
            }
        }
        currWeight++;
    }
}






