#include <algorithm>
#include <deque>
#include <iostream>

using namespace std;

#define pb push_back
#define REP(i,a,b) for(int i = a; i < b; i++)

deque<long> children;

int main(){
    long numChildren, maxWeight, currChild;
    cin >> numChildren >> maxWeight;
    REP(i, 0, numChildren){
        cin >> currChild;
        children.pb(currChild);
    }
    sort(children.begin(), children.end());
    int res = 0;
    while(children.size() > 0){
        if(children.size() == 1){
            res++;
            children.pop_back();
        }
        else if(children.front() + children.back() <= maxWeight){
            res++;
            children.pop_back();
            children.pop_front();
        }
        else{
            res++;
            children.pop_back();
        }
    }
    cout << res << endl;

    
}