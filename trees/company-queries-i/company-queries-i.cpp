#include <bits/stdc++.h>
using namespace std;

int parent[200001];
int ancestor[33][2000001];
/*
Want a node --> level mapping and similarly a
level ---> node...

Not really helpful? 

*/
int main(){
    parent[0] = 1;
    int n, q;
    cin >> n >> q;
    for(int i = 1; i < n; i++){
        cin >> parent[i];
    }
    parent[0] = -1;
    for(int node = 0; node < n; node++){
        int currOffset = 1;
        int currNode = node;
        for(level = 1; level < floor(log2(n)); level++){
            if(currNode == -1 || parent[currNode - 1] == -1){
                currNode = -1;
            }
            if(level == 1<<currOffset){
                ancestor[currOffset][node] = currNode;
                currOffset++;
            }
        }
    }

    int node, levels;
    while(q--){
        cin >> node >> levels;
        int curr = node;
        bool printed = false;
        for(int j = 0; j < levels; j++){
            if(parent[curr - 1] == -1){
                cout << -1 << endl;
                printed = true;
                break;
            }
            curr = parent[curr - 1];
        }
        if(!printed)
        cout << curr << endl;
    }
}