#include <bits/stdc++.h>
using namespace std;

#define REP(i,a,b) for(int i = a; i < b; i++)

int main(){
    int n, m;
    cin >> n >> m;
    vector<vector<int>> adj(n+1);
    REP(i,0,m){
        int s,t;
        cin >> s >> t;
        adj[s].push_back(t);
        adj[t].push_back(s);
    }
    vector<int> idle;
    REP(i,2,n + 1){
        idle.push_back(i);
    }

    unordered_set<int> g1 = {1};
    unordered_set<int> g2;
    deque<pair<int,int>> active = {make_pair(1, 0)};
    while(active.size() > 0 or idle.size() > 0){
        while(active.size() > 0){
            pair<int,int> curr = active.front();
            int childGroup = (curr.second^1);
            active.pop_front();
            for(int child : adj[curr.first]){

                if(childGroup == 0){
                    if(g2.count(child) > 0){
                        cout << "IMPOSSIBLE" << endl;
                        return 0;
                    }
                    else if(g1.count(child) == 0){
                        g1.insert(child);
                        active.push_back(make_pair(child, childGroup));
                    }
                }
                else{
                    if(g1.count(child) > 0){
                        cout << "IMPOSSIBLE" << endl;
                        return 0;
                    }
                    else if(g2.count(child) == 0){
                        g2.insert(child);
                        active.push_back(make_pair(child, childGroup));
                    }
                }
            }
        }
        while(idle.size() > 0 and (g1.count(idle.back()) > 0 or g2.count(idle.back()) > 0)){
            idle.pop_back();
        }
        if(idle.size() > 0){
            active.push_front(make_pair(idle.back(), 0));
            idle.pop_back();
        }
    }
    REP(i, 1,n + 1){
        if(g1.count(i) > 0){
            cout << "1 ";
        }
        else{
            cout << "2 ";
        }
    }
    cout << endl;

}