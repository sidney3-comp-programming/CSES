#include <bits/stdc++.h>
using namespace std;

#define REP(i,a,b) for(int i = a; i < b; i++)
typedef vector<int> vi;

int MOD = (int) 1e9+7;
vector<pair<int,int>> queries;
int res[1000001];

void solve(int maxQueries){
    long a = 1, b = 1;
    int queriesIdx = 0;
    if(queries[0].first == 1){
        res[queries[0].second] = 2;
        queriesIdx++;
    }
    REP(i, 1, maxQueries + 1){
        long newA = 2*a + b, newB = 4*b + a;
        a = newA % MOD;
        b = newB % MOD;
        while(i == queries[queriesIdx].first - 1){
            res[queries[queriesIdx].second] = (a+b)%MOD;
            queriesIdx++;
        }
    }
}

int main(){
    int t;
    cin >> t;
    int k;
    REP(i,0,t){
        cin >> k;
        queries.push_back(make_pair(k, i));
    }
    sort(queries.begin(), queries.end());
    solve(queries.back().first);
    REP(i,0,t){
        cout << res[i] << endl;
    }
}