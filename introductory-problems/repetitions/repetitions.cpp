#include <iostream>
#include <stdio.h>
#include <string.h>
#include <vector>

using namespace std;

int main() {
    char c;
    char prior = 'D';
    int res = 1, curr = 0;
    while(cin >> c){
       if(c == prior){
        res = max(res, ++curr);
       }
       else{
        curr = 1;
        prior = c;
       }
    }
    cout << res;
}