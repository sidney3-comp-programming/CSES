#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> ii;
typedef vector<pair<int,int>> vii;

#define REP(i,a,b) for(int i = a; i < b; i++)
#define pb push_back
#define mp make_pair
#define F first
#define S second
#define all(v) (v).begin(), (v).end()
#define sz size
#define putl(x) cout << x << endl;
#define put(x) cout << x << " ";
#define debug(x) cout << #x << ": " << x << endl;

bool mvis   [1001][1001];
bool vis    [1001][1001];
int  dis    [1001][1001];
char board  [1001][1001];
vector<char> cyc;
int n,m;

vii dirs = {
    {-1, 0},
    {0, 1},
    {1, 0},
    {0, -1}
};

vector<char> dirsLegend = {
    'U', 'R', 'D', 'L'
};


bool dfs(array<int, 3> node, array<int, 3> prev){
    auto [r,c,d] = node;
    vis[r][c] = true;
    REP(dir, 0, 4){
        int newR = r + dirs[dir].F;
        int newC = c + dirs[dir].S;

        if(dis[newR][newC] <= d + 1 or board[newR][newC] == '#') continue;
        cyc.pb(dirsLegend[dir]);
        if(newR == 0 or newC == 0 or newR == n - 1 or newC == m - 1) return true;
        if(!vis[newR][newC]){if(dfs({newR, newC, d + 1}, node)) return true;}
        cyc.pop_back();
    }
    vis[r][c] = false;
    return false;
}

int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> n >> m;
    deque<array<int, 3>> monsters;
    array<int, 3> start;

    REP(i,0,n){
        REP(j,0,m){
            cin >> board[i][j];
            dis[i][j] = (i+1)*(j+1);
            if(board[i][j] == 'A'){
                start = {i,j,0};
            }
            else if(board[i][j] == 'M'){
                monsters.pb({i,j,0});
                mvis[i][j] = true;
            }
        }
    }
    while(monsters.size() > 0){
        auto [r,c,d] = monsters.front();
        monsters.pop_front();
        dis[r][c] = d;
        for(ii next : dirs){
            if(
                r + next.F >= 0 &&
                r + next.F < n  && 
                c + next.S >= 0 && 
                c + next.S < m  && 
                board[r+next.F][c+next.S] != '#' &&
                !mvis[r+next.F][c+next.S]
                ){
                mvis[r+next.F][c+next.S] = true;
                monsters.push_back({r + next.F, c + next.S, 1 + d});
            }
        }
    }
    if(start[0] == 0 or start[0] == n-1 or start[1] == 0 or start[1] == m-1) cout << "YES"<<endl<<0<<endl;
    else if(dfs(start, {-1,-1,-1})){
        putl("YES");
        putl(cyc.size());
        for(char d : cyc) cout<<d;
        cout << endl;
    }
    else{
        putl("NO");
    }

}