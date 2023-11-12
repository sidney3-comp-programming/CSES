#include <bits/stdc++.h>
using namespace std;

int dp[200001];

bool cmp(vector<int> a, vector<int> b){
    return (a[1] <= b[1]);
}

int main(){
    int n;
    cin >> n;
    vector<vector<int>> intervals;
    
    int start, end, weight;

    for(int i = 0; i < n; i++){
        cin >> start >> end >> weight;
        intervals.push_back({start, end, weight})
    }
    sort(intervals.begin(), intervals.end(), cmp);
    dp[0] = intervals[0][2];
    int res = dp[0];
    set<pair<int, int>> starts;
    starts.add(make_pair(2, 3));
    starts.add(make_pair(3,4));
    cout << lower_bound(starts.begin(), starts.end(), 2)->first << endl;
    cout << lower_bound(starts.begin(), starts.end(), 1)->first << endl;

    // for(vector<int> s : starts){
    //     cout << s[0] << "," << s[1] << "," << s[2] << endl;
    // }
    // for(int i = 1; i < n; i++){
    //     int lb = lower_bound(starts, ends[i][1]);
    //     cout << "curr end: " << ends[i][1] << "lower bound bound: " << lb << endl;
    //     if(lb == -1){
    //         dp[i] = max(dp[i - 1], ends[i][2]);
    //     }
    //     else{
    //         dp[i] = max(dp[i-1], ends[i][2] + dp[lb]);
    //     }
    //     res = max(res, dp[i]);
    // }
    // cout << res << endl;
}