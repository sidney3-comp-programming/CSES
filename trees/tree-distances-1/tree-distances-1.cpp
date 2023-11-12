#include <bits/stdc++.h>
using namespace std;

#define MAX_SIZE 200001
#define REP(i,a,b) for(int i = a; i < b; i++)
#define mp make_pair
typedef vector<int> vi;
typedef pair<int, int> ii;

vector<vi> Adj(MAX_SIZE);
int dis[MAX_SIZE];
bool visitedLeft[MAX_SIZE];
bool visitedRight[MAX_SIZE];
bool visited[MAX_SIZE];

// returns (diameterNode1, diameterNode2, diameter)
// a bit bulky, buy want to avoid side effects
ii getDiameter() {
    ii res;
    deque<int> q = {1};
    fill(visited, visited + MAX_SIZE, false);
    visited[1] = true;
    while(q.size() > 0){
        deque<int> nextQ;
        for(int node : q){
            for(int child : Adj[node]){
                if(!visited[child]){
                    visited[child] = true;
                    nextQ.push_back(child);
                }
            }
        }
        if(nextQ.size() == 0)
            res.first = q.front();
        q = nextQ;
        cout << endl;
    }
    fill(visited, visited + MAX_SIZE, false);

    q.push_back(res.first);
    visited[res.first] = true;
    while(q.size() > 0){
        deque<int> nextQ;
        for(int node : q){
            for(int child : Adj[node]){
                if(!visited[child]){
                    visited[child] = true;
                    nextQ.push_back(child);
                }
            }
        }
        if(nextQ.size() == 0)
            res.second = nextQ.front();
        q = nextQ;
    }
    cout << "finished diameter calculation" << endl;
    return res;
}

int main(){
    int n, a, b;
    cin >> n;
    REP(i, 0, n - 1){
        cin >> a >> b;
        Adj[a].push_back(b);
        Adj[b].push_back(a);
    }
    ii diameters = getDiameter();

    deque<ii> q = {mp(diameters.first, 0)};
    visitedLeft[diameters.first] = true;
    while(q.size() > 0){
        ii curr = q.front();
        q.pop_front();
        dis[curr.first] = curr.second;
        for(int child : Adj[curr.first]){
            if(child != curr.first && !visitedLeft[child]){
                visitedLeft[child] = true;
                q.push_back(mp(child, curr.second + 1));
            }
        }
    }
    q.push_back(mp(diameters.second, 0));
    visitedRight[diameters.second] = true;
    while(q.size() > 0){
        ii curr = q.front();
        q.pop_front();
        dis[curr.first] = max(dis[curr.first], curr.second);
        for(int child : Adj[curr.first]){
            if(child != curr.first && !visitedRight[child]){
                visitedRight[child] = true;
                q.push_back(mp(child, curr.second + 1));
            }
        }
    }

    REP(node, 1, n + 1){
        cout << dis[node] << " ";
    }
    cout << endl;
}
