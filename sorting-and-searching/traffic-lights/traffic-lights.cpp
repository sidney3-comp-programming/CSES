#include <iostream>
#include <set>
#include <utility>
#include <queue>
#include <algorithm>

using namespace std;

#define REP(i,a,b) for(int i = a; i < b; i++)
#define pb push_back

multiset<int> sizes;
set<int> partitions;
vector<int> lights;


int main(){
    int streetLen, numLights;
    cin >> streetLen >> numLights;

    int currPartition;
    partitions.insert(0);
    partitions.insert(streetLen);
    sizes.insert(streetLen);

    REP(i, 0, numLights){
        cin >> currPartition;
        lights.pb(currPartition);
    }
    for(int partition : lights) {
        auto end = partitions.upper_bound(partition);
        auto start = end;
        start--;
        sizes.insert(*end - partition);
        sizes.insert(partition - *start);
        sizes.erase(sizes.find(*end - *start));
        partitions.insert(partition);
        auto ans = sizes.end();
        ans--;
        cout << *ans << " ";
    }
    cout << endl;
}