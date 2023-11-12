#include <bits/stdc++.h>
using namespace std;
#define mp make_pair
#define REP(i,a,b) for(int i = a; i < b; i++)

typedef pair<int, int> ii;

int main(){
    int n;
    cin >> n;
    vector<ii> tasks(n);
    int dur, dead;
    REP(i,0,n){
        cin >> dur >> dead;
        tasks[i] = mp(dur, dead);
    }
    sort(tasks.begin(), tasks.end(), [](ii a, ii b){return a.first < b.first;});
    long S = 0;
    long res = 0;
    REP(i,0,n){
        S += (long) tasks[i].first;
        res += (long) (tasks[i].second - S);
    }
    cout << res << endl;

}