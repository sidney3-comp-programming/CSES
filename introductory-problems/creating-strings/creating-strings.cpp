#include <algorithm>
#include <deque>
#include <iostream>
#include <unordered_set>
#include <vector>

#define REP(i,a,b) for(int i = a; i < b; i++)

using namespace std;

deque<char> inputString;


bool comparePermutations(vector<char> perm1, vector<char> perm2){
    REP(i, 0, min(perm1.size(), perm2.size())){
        if(int(perm2[i]) > int(perm1[i])){
            return true;
        }
        else if(int(perm2[i]) < int(perm1[i])){
            return false;
        }
    }
    return perm2.size() > perm1.size();
}

vector<vector<char>> permutations(deque<char> inp){
    if(inp.size() == 1){
        return {{inp.front()}};
    }
    vector<vector<char>> res;
    REP(i, 0, inp.size()){
        char top = inp.front();
        inp.pop_front();
        for(vector<char> perm : permutations(inp)) {
            perm.push_back(top);
            res.push_back(perm);
        }
        inp.push_back(top);
    }
    return res;
}

string convertVec(vector<char> vec){
    string res = "";
    for(char c : vec){
        res += c;
    }
    return res;
}

int main(){
    char c;
    while(cin >> c){
        inputString.push_back(c);
    }
    vector<vector<char>> perms = permutations(inputString);
    sort(perms.begin(), perms.end(), comparePermutations);

    unordered_set<string> printed;
    vector<string> toPrint;

    for(vector<char> str : perms){
        string s = convertVec(str);
        if(printed.count(s) == 0){
            printed.insert(s);
            toPrint.push_back(s);
        }
    }
    cout << toPrint.size() << endl;
    for(string s : toPrint){
        cout << s << endl;
    }
}
/*
Expected:
aaabc
aaacb
aabac
aabca
aacab
aacba
abaac
abaca
abcaa
acaab
acaba
acbaa
baaac
baaca
bacaa
bcaaa
caaab
caaba
cabaa
cbaaa

*/