#include <bits/stdc++.h>
using namespace std;

#define REP(i,a,b) for(int i = a; i < b ;i++)

typedef vector<int> vi;

int main(){
    int n;
    cin >> n;
    vi arr(n);
    REP(i,0,n){
        cin >> arr[i];
    }
    vi stack;
    vi res;
    REP(k, 0, n){
        while(stack.size() > 0 and arr[stack.back()] >= arr[k]){
            stack.pop_back();
        }
        if(stack.size() == 0){
            res.push_back(0);
        }
        else{
            res.push_back(stack.back()+1);
        }
        stack.push_back(k);
    }
    for(int m : res){
        cout << m << " ";
    }
    cout << endl;

}