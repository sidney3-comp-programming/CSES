#include <iostream>
#include <deque>
#include <cmath>
#include <string>
#include <map>
#include <cstdio>
#include <utility>
#include <cstdlib>
#include <vector>
#include <unordered_map>

using namespace std;

#define all(x) (x.begin(), x.end())
#define pb push_back

unordered_map<char, int> freq;
vector<pair<char, int>> toPrint;
deque<char> res;

int main(){
    char c;
    pair<bool, char> middleChar = {false, '\0'};
    while(cin >> c){
        freq[c]++;
    }
    for(auto &pair : freq){
        if(pair.second % 2 != 0){
            if(middleChar.first){
                cout << "NO SOLUTION\n";
                return 0;
            }
            else{
                middleChar.first = true;
                middleChar.second = pair.first;
            }
        }
        if(pair.second > 1) toPrint.pb({pair.first, floor(pair.second / 2)});
    }
    for(auto it = toPrint.begin(); it != toPrint.end(); it++){
        string chars = string((*it).second, (*it).first);
        cout << chars;
    }
    if(middleChar.first){
        cout << middleChar.second;
    }
    for(auto it = toPrint.rbegin(); it != toPrint.rend(); it++){
        string chars = string((*it).second, (*it).first);
        cout << chars;
    }
}